#pragma once
 
#include "element.h"

template <typename K, typename DT>
class myMap 
{
	typedef Element<K, DT> myElement;

private:
	myElement  *elements; //Container for the data.
	int size; // Size of the map
		
public:

	//Constructor (setup the array)
	myMap();

	//Need a copy constructor

	myElement operator[] (K key)
	{
		for (int i = 0; i<size; i++)
		{
			if (elements[i].key == key)
				return elements[i].data;
		}
	}

	//Checks to see if the item is already in the Map
	bool IsItem(K key)
	{
		for (int i = 0; i<size; i++)
		{
			if (elements[i].key == key)
				return true;
		}
		return false;
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
	
	//0 key signals that the array element is empty.
	for (int i = 0; i < size; i++)
	{
		elements[i].key = 0;
	}

}

/**The insert operation checks if the key is already present and if it is then the value wont be inserted.
If the array is almost full a new one is created and the contents copied over.**/
template <typename K, typename DT>
void myMap<K, DT>::insert(const K &key, const DT &val)
{
	
	myElement *temp = new myElement;
	temp->key = key;
	temp->data = val;

	if (IsItem(key) == false){
		for (int i = 0; i < size; i++)
		{
			//Search for an empty element, users key can't be 0. Need to change this.
			if (elements[i] == 0){
				elements[i] = *temp;
				cout << "inserted at " << i << " " << elements[i].key << " " << elements[i].data << endl;// debug code
				break;
			}
		}
	}

	delete temp;
}