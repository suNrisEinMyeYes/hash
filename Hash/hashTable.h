#pragma once
#include "stdafx.h"
#include <iostream>
#include "hashFunction.h"
#include "fileReader.h"
#include "comparator.h"
#include <list>
#include <iterator>
using std::list;
using namespace std;
template<typename T>
class hashTable
{
private:
	list<T> * table;
	list<string>::iterator it;
	hashFunction hasher;
	comparator<T> sorter;
public:
	
	hashTable();
	void add();
	void remove(string * elemToDelete);
	list<string>::iterator find(string * elemToFind);
	void print();
};
