#pragma once
#include "stdafx.h"
#include <iostream>
#include "hashTable.h"
#include <list>
using std::list;
template<class T>
class hashTable
{
private:
	list<T> * table;
public:
	
	hashTable();
 	void test();
};

