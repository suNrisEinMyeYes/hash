#include "stdafx.h"
#include "comparator.h"
#include "stdafx.h"
#include <iostream>
#include <list>

#include <string>
using namespace std;
using std::list;
using std::string;
template<typename T>
void comparator<T>::sort(list<T> & A)
{
	A.sort();
}
