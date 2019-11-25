#include "stdafx.h"
#include <iostream>
#include "fileReader.h"
#include <fstream>
#include <string>
using namespace std;
ifstream  fileReader::read()
{
	ifstream  file;
	string fileName;
	cin >> fileName;
	file.open(fileName);
	return file;
}
