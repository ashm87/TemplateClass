#pragma once
 
#include "element.h";

template <typename K, typename DT>
class myMap 
{
	typedef Element<K, DT> myElement;

private:
	myElement  *elements;
	int size;
		
public:

	//Constructor (setup the array)
	myMap();

	myElement operator[] (int index)
	{
		return elements[index];
	}
		
	void insert(const K &key, const DT &val);

	//Modifies the data for the supplied key.
	void update(K key, DT &newData);

	//Returns the data with associated key.
	DT find(K key);
	
	//Erases the data for the given key.
	void myMap<K, DT>::erase(K key)
	{

	}

	//Destructor (free the memory)
	~myMap();
	
};

template <typename K, typename DT>
myMap<K, DT>::myMap()
{
	//An initial map with a size of 10 potential elements.
	size = 10;
	elements = new myElement[size];
	
	for (int i = 0; i < size; i++)
	{
		elements[i].data = 0;
	}
}

//The insert operation checks if the key is already present and if it is then the value wont be inserted.
//If the array is almost full a new one is created and the contents copied over.
template <typename K, typename DT>
void myMap<K, DT>::insert(const K &key, const DT &val)
{

	/*A temporary element to store the data which is then stored
	in the array.*/

	myElement *temp = new myElement;
	temp->key = key;
	temp->data = val;
	
	
	
	delete temp;
}
