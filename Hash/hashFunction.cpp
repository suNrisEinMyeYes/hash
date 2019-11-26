#include "stdafx.h"
#include <iostream>
#include "hashFunction.h"
#include <string>
using namespace std;
int hashFunction::hash(string & A)
{
	int result = int(A[0]);

	for (int i = 1; i < A.length(); i++)
	{
		result *= 2;
		result += A[i];
	}
	result %= 100;
	
	return result;
}


