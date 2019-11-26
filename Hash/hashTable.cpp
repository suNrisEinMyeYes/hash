#include "stdafx.h"
#include <iostream>
#include "hashFunction.h"
#include "fileReader.h"
#include "comparator.h"
#include "hashTable.h"
#include <list>
#include <iterator>

using std::list;
using namespace std;
template <typename T>
	hashTable<T>::hashTable() {
		table = new list<T>[100];
	}
	/*int getKey(string * elem){
	return(hasher.hash(elem));
	}*/
	template <typename T>
	void hashTable<T>::add() {
		ifstream file = fileReader::read();
		string  reader;
		while (!file.eof())
		{
			file >> reader;
			int index = hasher.hash(reader);
			table[index].push_back(reader);
		}
		file.close();
		/*for (int i = 0; i < 100; i++)
		{
		//if (table[i]!=NULL)
		//{
		sorter.sort(table[i]);
		//}
		}*/
	}
	template <typename T>
	void hashTable<T>::remove(string * elemToDelete) {
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
	template <typename T>
	list<string>::iterator hashTable<T>::find(string * elemToFind) {

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
		cout << "Not found: " << elemToFind << endl;
		//cout << *it << endl;
		//cout << it << endl;
		return it;
	}
	template <typename T>
	void hashTable<T>::print() {
		for (size_t i = 0; i < 100; i++)
		{
			cout << i << ": ";
			copy(table[i].begin(), table[i].end(), ostream_iterator<T>(cout, " "));
			cout << endl;
		}

	}
