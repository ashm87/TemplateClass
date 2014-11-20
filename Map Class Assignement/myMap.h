#pragma once
 
#include "element.h"
#include <iostream>

template <typename K, typename DT>
class myMap 
{
	typedef Element<K, DT> myElement;

private:
	myElement  *elements; //Container for the data.
	int size; // Size of the map
		
public:

	myMap();

	//Need a copy constructor
	
	DT& operator[](K key);

	
	//Checks to see if the data is already in the Map
	bool isData(K key)
	{
		for (int i = 0; i<size; i++)
		{
			if (elements[i].key == key)
				return true;
		}
		return false;
	}
		
	void insert(const K &key, const DT &val);
	
	void update(K key, const DT &newData); //Modifies the data for the supplied key.
	
	DT& find(K key);//Returns the data with associated key.
	
	void erase(K key);//Erases the data for the given key.

	~myMap();//Destructor (free the memory)
	
};

template <typename K, typename DT>
myMap<K, DT>::myMap()
{
	//An initial map with a size of 10 potential elements.
	size = 10;
	elements = new myElement[size];
	
}

/**The insert operation checks if the key is already present and if it is then the value wont be inserted.
If the array is almost full a new one is created and the contents copied over. Returns an int, the position of the new element**/
template <typename K, typename DT>
void myMap<K, DT>::insert(const K &key, const DT &val)
{	
	if (!isData(key))//If the data isn't found in the map, then we can proceed.
	{ 
		myElement *temp = new myElement;
		temp->key = key;
		temp->data = val;
		temp->isEmpty = false;

		for (int i = 0; i < size; i++){	
			if (elements[i].isEmpty)//Search for an empty element.
			{
				elements[i] = *temp;
				cout << "inserted at " << i << ": " << elements[i].key << " " << elements[i].data << endl;// debug code
				break;
			}
		}
		delete temp;
	}
}

/**The find operation returns the data that is associated with the supplied key. **/
template <typename K, typename DT>
DT& myMap<K, DT>::find(K key)
{
	for (int i = 0; i<size; i++)
	{
		if (elements[i].key == key)		
		{
			return elements[i].data;
		}
	}	
}

template <typename K, typename DT>
void myMap<K, DT>::update(K key, const DT &newData)
{
	for (int i = 0; i<size; i++)
	{
		if (elements[i].key == key){
			elements[i].data = newData;
		}
	}
}

template <typename K, typename DT>
void myMap<K, DT>::erase(K key)
{




}

template <typename K, typename DT>
DT& myMap<K, DT>::operator[](K key)
{
	int emptyElement = 0;

	for (int i = 0; i<size; i++)
	{
		if (elements[i].key == key)
		{
			return elements[i].data;
		}
		if (elements[i].isEmpty){//Store the first empty element found incase we don't find the key in the map
			emptyElement = i;
		}
	}

	myElement *temp = new myElement;
	temp->key = key;
	temp->isEmpty = false;
	elements[emptyElement] = *temp;

	delete temp;
	return elements[emptyElement].data;
}

