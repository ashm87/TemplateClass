#pragma once

#include "myMap.h"

//The Element class holds the individual data for each item in the map.
//K is the key data type and DT is the type of data that is to be stored
template <typename K, typename DT>
class Element
{
	 
	 template <typename K, typename DT> friend class myMap;//Allows myMap class access to the private data of Element.

private:
	K key;
	DT data;
	bool isEmpty = true; //Check if the element is free to been written to. Default to true.
};

