#pragma once

#include "Element.h"
#include "ElementNotFoundException.h"

template <typename K, typename DT>
class myMap 
{
	typedef Element<K, DT> myElement;

private:
	myElement  *elements; //Container for the data.	
	myElement nullElement; //To store once a deletion has been made.

	int size; // Potential size of the map.
	int numOfElements;// How many elements are currently held in the map.

	void resizeMap(); //Doubles the map size. Private: We want the map to manage this its self.
		
public:
	myMap(); //constructor

	//Returns the potenital size of the map
	int getCapacity(){
		return size;
	}
	
	//Returns how many elements are held in the map 
	int getNumOfElements(){
		return numOfElements;
	}
	
	DT& operator[](K key); //subscript operator
			
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
		
	void insert(const K &key, const DT &val); //Inserts a new element into an empty position
	
	DT& find(K key);//Returns the data with the associated key.

	void update(K key, const DT &newData); //Modifies the data for the supplied key.
	
	void erase(K key);//Erases the data for the given key.	

	~myMap();//Destructor (free the memory)
};

//Constructor
template <typename K, typename DT>
myMap<K, DT>::myMap()
{
	//An initial map with a capacity of 8 potential elements.
	size = 8;
	numOfElements = 0;

	elements = new myElement[size];
}

//Operator []
template <typename K, typename DT>
DT& myMap<K, DT>::operator[](K key)
{
	int emptyElement = -1;

	if (numOfElements == size){
		//Check if the array is full
		resizeMap();
	}

	for (int i = 0; i<size; i++)
	{
		if (elements[i].key == key){ //If key is found, return the data
			return elements[i].data;
		}
		if (elements[i].isEmpty && emptyElement == -1){ //Store the first empty element found incase we don't find the key in the map
			emptyElement = i;
		}
	}

	//If key isn't found then create a new element in the map to store the data.
	myElement *temp = new myElement;
	
	temp->key = key;
	temp->isEmpty = false;	
	elements[emptyElement] = *temp;

	numOfElements++;

	delete temp;
	return elements[emptyElement].data;
}

template<typename K, typename DT>
void myMap<K, DT>::resizeMap()
{
	myElement * tempElements = new myElement[size*2]; //Create an array with enough space to work with

	std::copy(elements, elements + size, tempElements);//Copy the array to temporary storage.

	delete[] elements; //Delete the old data

	elements = tempElements; //Reassign to the new data

	size = size * 2; //Double the size.
}

/**The insert operation checks if the key is already present and if it is then the value wont be inserted.
If the array is full a new one is created and the contents copied over.**/
template <typename K, typename DT>
void myMap<K, DT>::insert(const K &key, const DT &val)
{	
	if (numOfElements == size){
		//Check if the array is full
		resizeMap();
	}

	if (!isData(key))//If the data isn't found in the map, then we can proceed.
	{ 
		myElement *temp = new myElement;
		temp->key = key;
		temp->data = val;
		temp->isEmpty = false;

		for (int i = 0; i < size; i++){	
			if (elements[i].isEmpty)
			{
				elements[i] = *temp;
				numOfElements++;
				break; //Only insert once
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
		if (elements[i].key == key && !elements[i].isEmpty)		
		{
			return elements[i].data;
		}
	}
	throw ElementNotFoundException();
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
	for (int i = 0; i<size; i++)
	{
		if (elements[i].key == key){
			elements[i] = nullElement;
			numOfElements--; //decriment, more space to write to in the map.
		}
	}
}

template<typename K, typename DT>
myMap<K, DT>::~myMap()
{
	delete[] elements;
}

