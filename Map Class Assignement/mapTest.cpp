// Map Class Assignement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "myMap.h"

#include<map>

#include <string>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	try{	

		myMap <string, string> phoneBook; //test <string, string>
		myMap <string, int> age; //test <string, int>
		myMap <char*, float> symbols;
	
		map <string, string> mapAge;
	
		//Test 1-----
		cout << "(myMap) Test 1 is a phone book (string, string), current capcity is: " << phoneBook.getCapacity()
			<< endl << " and it contains: " << phoneBook.getNumOfElements() << " elements" << endl << endl;

		phoneBook.insert("Alice Clark", "07850441348"); //test insert using method.
		phoneBook["Graham Jones"] = "07855611905"; //test using subscript operator

		cout << "Insert 2 Elements..." << endl << endl;
		cout << "Map expected to contain 2 Elements" << endl;
		cout << "Map now contains: " << phoneBook.getNumOfElements() << endl;
		if (phoneBook.getNumOfElements() == 2){
			cout << "Test passed" << endl << endl;
		}
		else{
			cout << "Test failed " << endl <<endl;
		}

        cout <<"Test output: " << endl;
		cout << "Alice Clark phone number: " << phoneBook.find("Alice Clark") << endl; //test output using find mehod.
		cout << "Graham Jones phone number: " << phoneBook["Graham Jones"] << endl <<endl; //test output using operator
		
		phoneBook.erase("Alice Clark");//test erase method
		cout << "Test erase method. Erase: Alice Clark" << endl;
		cout << "Map expected to contain 1 Element" << endl;
		cout << "Map now contains: " << phoneBook.getNumOfElements() << endl;
		if (phoneBook.getNumOfElements() < 2){
			cout << "Test passed" << endl << endl;
		}
		else{
			cout << "Test failed " << endl << endl;
		}

		//Test 2 -----
		cout << "(myMap) Test 2 = (string, int), current capcity is: " << age.getCapacity()
			<< endl << " and it contains: " << age.getNumOfElements() << " elements" << endl << endl;

		age.insert("rob", 24);
		
		age["mike"] = 28;
		cout << "Mike is " << age["mike"] << endl;

		age.insert("mike", 88); //check duplicates not allowed
		cout << "Test insertion using a duplicate key: " << endl;
		if (age["mike"] == 88){
			cout << "Test failed" << endl << endl;
		}
		else{
			cout << "Test passed" << endl << endl;
		}
		
		age["sarah"] = 62;
		age["vicky"] = 23;
		age["chris"] = 55;
		age["paul"] = 47;
		age["nick"] = 50;
		age["tony"] = 90;
		age["lisa"] = 20; 
		
		//demonstrates that the map dynamically grows, no fixed size.
		cout << "Demonstrate that the map dynamiclly grows, no fixed size: " << endl;
		cout << "Now contains: " << age.getNumOfElements() << " elements:" << endl;
		if (age.getNumOfElements() > 8){
			cout << "Test passed" << endl << endl;
		}
		else{
			cout << "Test failed" << endl << endl;
		}

		cout << "Capcity is now: " << age.getCapacity() << ", map has resized" << endl;
		if (age.getCapacity() > 8){
			cout << "Test passed" << endl << endl;
		}
		else{
			cout << "Test failed" << endl << endl;
		}

		age.update("mike", 29); //test update method
		cout << "Mike's birthday, he is now: " << age["mike"] << endl;
		cout << "Lisa is " << age["lisa"] << endl;

		age["lisa"] = 21; //test reassignment via operator
		cout << "Lisa's birthday, she is now: " << age["lisa"] << endl <<endl;		

		cout << "Test 3 = <char*, float>: " << endl;
		symbols["p"] = 3.14159;
		cout <<"pi is: " << symbols["p"] << endl;
	 
	}

	catch (exception &ex)
	{
		cout <<"Exception thrown! " << ex.what() << endl; 
	}

	system("PAUSE");

	_CrtDumpMemoryLeaks();
	return 0;
}