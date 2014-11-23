// Map Class Assignement.cpp : Defines the entry point for the console application.
//

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "stdafx.h"
#include "myMap.h"

#include<map>

#include <string>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try{	

		myMap <string, int> test;
		map<string, int> test2;

		myMap<float, int> test3;

		test.insert("vicky", 23);
		test.insert("bob", 28);
		test.insert("frank", 44);
		test.insert("steve", 66);
		test.insert("roberto", 25);
		test.insert("paulo", 66);
		test["neil"] = 58;
		test["kath"] = 55;
		test["bill"] = 13;
		test["Kurt"] = 55;

	

	}

	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	system("PAUSE");

	_CrtDumpMemoryLeaks();
	return 0;
}