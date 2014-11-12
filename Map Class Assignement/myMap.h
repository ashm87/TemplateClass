#pragma once

//The Element class holds the individual data for each item in the map.
//K is the key data type and DT is the type of data that is to be stored
template <typename K, typename DT>
class Element
{
	//friend class myMap<K,DT> //Allows myMap class access to the private data of Element at the expense of tighter coupling.

public:
	K key;
	DT data;
};

template <typename K, typename DT>
class myMap 
{
	
private:
	Element<K, DT> * elements;

public:

	//Constructor (setup the array)
	myMap<K, DT>::myMap()
	{
		elements = new Element[10];
	}
	
	//The insert operation checks if the key is already present and if it is then the value wont be inserted.
	//If the array is almost full a new one is created and the contents copied over.
	void myMap<K, DT>::insert(K key, DT &val)
	{
		/*A temporary element to store the data which is then stored
		in the array.*/
		Element<K, DT> * temp = new Element;
		temp->key = key;
		temp->data = val;

		elements[0] = temp;


	}

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

