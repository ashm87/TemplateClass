// Map Class Assignement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myMap.h"

#include <string>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try{

		myMap<string, int> * test = new myMap < string, int > ;

		myMap <int, int> test2;

		test->insert("lemon", 5);
		test->insert("lemon", 6);
		test->insert("diamond", 500);
		test->insert("emerald", 60000);
		
		test->insert("frog", 555333);
		

		cout << "test output is: " << test->find("diamnd");
		
		test->update("lemon", 855);

		cout << "test output is: " << test->find("lemon");

		//test2["car"] = 22;

	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}