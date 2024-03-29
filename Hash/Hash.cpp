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
using std::list;
using std::string;
template <typename T>
class hashTable{
		
		list<T> * table;
		list<string>::iterator it;
		hashFunction hasher;
		comparator<T> sorter;
		
	public:
		hashTable() {
			table = new list<T>[100];
		}
		
		void add (){
			ifstream file = fileReader::read();
			T  reader;
			while (!file.eof())
			{
				file >> reader;
				int index = hasher.hash(reader);
				table[index].push_back(reader);
			}
			file.close();
			
			for (int i = 0; i < 100; i++)
			{
				sorter.sort(table[i]);
			}
		}
		void remove (T * elemToDelete){
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
		list<string>::iterator find(T * elemToFind) {

			int index = hasher.hash(*elemToFind);
			int numbInList = 0;
			for (it = table[index].begin(); it != table[index].end(); it++) {
				if (*it == *elemToFind)
				{
					return it;
				}
				numbInList++;
			}
			cout << "Not found: " << elemToFind << endl;
			return it;
		}
};
int main()
{
	hashTable<string> A;
	A.add();
    return 0;
}

