// Hash.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
#include "hashFunction.h"
#include "hashTable.h"
#include <list>
#include <iterator>

using namespace std;
template <class T>
class abc{
	
		list<T> * table;
	public:
		abc() {
			table = new list<T>[100];
		}
		void test(){
			table[0].push_back(25);
			table[0].push_back(26);
			table[0].push_back(27);
			copy(table[0].begin(), table[0].end(), ostream_iterator<T>(cout, " "));
		}
	
};
int main()
{
	//abc<int> k;
	//k.test();
	//list<int> * k;
	//hashTable<int> V;
	system("pause");
    return 0;
}

