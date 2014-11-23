#pragma once
#include "Element.h"

template <typename K, typename DT>
class myMap 
{
	typedef Element<K, DT> myElement;

private:
	myElement  *elements; //Container for the data.
	
	int size; // Potential size of the map.
	int numOfElements;// How many elements are held in the map.
		
public:
	myMap(); //constructor
	~myMap();//destructor (free the memory)

	//Operators:
	DT& operator[](K key); //subscript for writing to
			
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

	void resizeMap(); //doubles the map size
		
	void insert(const K &key, const DT &val); //inserts a new element into an empty position

	void update(K key, const DT &newData); //Modifies the data for the supplied key.
	
	DT& find(K key);//Returns the data with associated key.
	
	void erase(K key);//Erases the data for the given key.	
};

//Constructor
template <typename K, typename DT>
myMap<K, DT>::myMap()
{
	//An initial map with a size of 10 potential elements.
	size = 8;
	numOfElements = 0;

	elements = new myElement[size];
}


//Operator []
template <typename K, typename DT>
DT& myMap<K, DT>::operator[](K key)
{
	if (numOfElements == size){
		//Check if the array is full
		resizeMap();
	}

	int emptyElement = -1;

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
	temp->data = 0;
	temp->isEmpty = false;
	elements[emptyElement] = *temp;

	cout << "inserted at " << emptyElement<< ": " << elements[emptyElement].key << " " << elements[emptyElement].data << endl;// debug code

	numOfElements++;

	delete temp;
	return elements[emptyElement].data;
}

template<typename K, typename DT>
void myMap<K, DT>::resizeMap()
{
	myElement * tempElements = new myElement[size*2]; //Create an array with enough space to work with

	std::copy(elements, elements + size, tempElements);

	delete[] elements; //Delete the old data

	elements = tempElements; //Reassign to the new data

	size = size * 2; //Double the size.

	cout << "resize called, the array is now:" << size << endl;
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
			if (elements[i].isEmpty)//Search for an empty element.
			{
				elements[i] = *temp;
				cout << "inserted at " << i << ": " << elements[i].key << " " << elements[i].data << endl;// debug code
				numOfElements++;
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
		if (elements[i].key == key && !elements[i].isEmpty)		
		{
			return elements[i].data;
		}	
	}
	//Throw exception
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
	//throw exception
}

template <typename K, typename DT>
void myMap<K, DT>::erase(K key)
{
	for (int i = 0; i<size; i++)
	{
		if (elements[i].key == key){			
			elements[i].data = 0;
			elements[i].isEmpty = true; // Ready to be written to again.

			numOfElements--; //decriment, more space to write to in the map again.
		}
	}
	//throw exception
}

template<typename K, typename DT>
myMap<K, DT>::~myMap()
{
	delete[] elements;
}

