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

	bool isEmpty = true; //Check if the element has been written to or not.
};

