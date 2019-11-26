#pragma once
#include "stdafx.h"
#include <iostream>
#include <list>

#include <string>
using namespace std;
using std::list;
using std::string;
template<typename T>
class comparator
{
public:
	virtual	 void sort(list<T> & A) {
		A.sort();
}
};


