// Hash.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
#include "hashFunction.h"
#include "fileReader.h"
#include "comparator.h"
#include <list>
#include <iterator>

using namespace std;
template <typename T>
class hashTable{

		list<T> * table;
		list<string>::iterator it;
		hashFunction hasher;
		
	public:
		hashTable() {
			table = new list<T>[100];
		}
		/*int getKey(string * elem){
			return(hasher.hash(elem));
		}*/
		void add (){
			ifstream file = fileReader::read();
			string  reader;
			while (!file.eof())
			{
				file >> reader;
				int index = hasher.hash(reader);
				table[index].push_back(reader);
			}
			file.close();
		}
		void remove (string * elemToDelete){
			it = find(elemToDelete);
			int index = hasher.hash(*elemToDelete);
			if (it == table[index].end())
			{
				cout << "nothing to remove" << endl;
				return;
			}
			
			table[index].erase(it);
			cout << "removed!" << endl;
		}
		list<string>::iterator find(string * elemToFind) {

			int index = hasher.hash(*elemToFind);
			cout << "hash key:" << index << endl;
			int numbInList = 0;
			for (it = table[index].begin(); it != table[index].end(); it++) {
				if (*it == *elemToFind)
				{
					return it;
				}	
				numbInList++;
			}
			cout << "Not found: " << elemToFind<<endl;
			//cout << *it << endl;
			//cout << it << endl;
				return it;
		}
		void print(){
			for (size_t i = 0; i < 100; i++)
			{	cout << i << ": ";
				copy(table[i].begin(), table[i].end(), ostream_iterator<T>(cout, " "));
				cout << endl;
			}
			
		}
};
int main()
{
	hashTable<string> V;
	string B = "123";
	
	V.add();
	V.remove(&B);
    return 0;
}

