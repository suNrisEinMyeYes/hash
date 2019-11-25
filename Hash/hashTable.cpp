#include "stdafx.h"
#include <iostream>
#include "hashTable.h"
#include <list>
#include <iterator>
using namespace std;

template <class T>
hashTable<T>::hashTable()
{
	table = new list<T>[100];
}
template <class T>
void hashTable<T>::test() 
{
	table[0].push_back(25);
	table[0].push_back(26);
	table[0].push_back(27);
	copy(table[0].begin(), table[0].end(), ostream_iterator<T>(cout, " "));
}

