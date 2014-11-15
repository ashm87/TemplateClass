// Map Class Assignement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myMap.h"
#include <string>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	myMap<int, int> * test = new myMap<int, int>;
	myMap<string, float> * test2 = new myMap<string, float>();

	test->insert(3, 2);
	test->insert(3, 1);

	
	
	
	

	return 0;
}

