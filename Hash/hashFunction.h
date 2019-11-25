#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>
using std::string;
class hashFunction
{
	
public:
	hashFunction();
	virtual int hash(string & A);
};

