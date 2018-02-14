//Bryant Wong CSCi 2421 Homework 2

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove Template and Inheritance

/** @file ArrayBag.cpp */

#include "ArrayBag.h"

//default constructor, sets array size to 0 and the max size to DEFAULT_BAG_SIZE (100 for right now)
ArrayBag::ArrayBag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor


//returns the private member integer itemCount representing the number of elements in the array
int ArrayBag::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize


//checks to see if the ArrayBag items has 0 elements and retuns true if it is empty
bool ArrayBag::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

//checks to see if ArrayBag items has reached max size, if it has not, then adds the specified item
//and increases items' current size
bool ArrayBag::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);	
	if (hasRoomToAdd)		
	{
		items[itemCount] = newEntry;	//if boolean stating the size of the array is less than the array's max size, adds the passed int newEntry to the array
		itemCount++;		//increments the size of the array after accepting newEntry
	}  // end if
    
	return hasRoomToAdd;	
}  // end add

//finds the index number of a given item and removes it and reduces the array items' current size
bool ArrayBag::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);	//sets the local variable locatedIndex to the value of the index of a passed int anEntry
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);		//checks if the array is not empty and the index of anEntry is 0 or greater
	if (canRemoveItem)	//if the bool is true..
	{
		itemCount--;	//decrements the number of items in the bag
		items[locatedIndex] = items[itemCount];	//sets the index of anEntry to the max size of the array, outside of the array to effectively remove it from the array
	}  // end if
    
	return canRemoveItem;
}  // end remove

//removes all items from the array by setting its size to 0
void ArrayBag::clear()
{
	itemCount = 0;
}  // end clear

//checks to see if an item exists in array items.  if it does, increments
//frequency to keep track of how many there are in the array
int ArrayBag::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int searchIndex = 0;
   while (searchIndex < itemCount)		//while the index of a passed anEntry is less than the number of elements in the array...
   {
      if (items[searchIndex] == anEntry)	//if an item in the array is equal to the passed value
      {
         frequency++;		//increments the counter
      }  // end if
      
      searchIndex++;
   }  // end while
   
   return frequency;	//returns an int representing the number of times anEntry is found in the array
}  // end getFrequencyOf


//checks to see if array items contains a specific value and returns the index number of that item
bool ArrayBag::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains


//converts the array items into a vector
std::vector<ItemType> ArrayBag::toVector() const
{
    std::vector<ItemType> ArrayBagContents;		//creates a local vector object named ArrayBagContents
	for (int i = 0; i < itemCount; i++)		
                ArrayBagContents.push_back(items[i]);	//for loops through the array and adds each item to the vector
   return ArrayBagContents;
}  // end toVector



//searches the array items for a specified "target" and returns the index number
//of the first item found if it exists
int ArrayBag::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   // if the ArrayBag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))	//if the passed value target has not been found...
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;	//local variable result is set to the index of the item in the array
      } 
      else
      {
         searchIndex++;	
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf


//display values of an ArrayBag bag.  from validateInput.cpp Dr. Augustine, 
//modified to output contents of an array

void ArrayBag::printValues()
{
	for (int count = 0; count < itemCount; count++)		//for loop to cycle through the array
	{
		std::cout << items[count] << " ";	//prints out the element value of items[count]
	}
	std::cout << std::endl;
}

//overloaded[] operator to use items as an array within member functions
ItemType ArrayBag::operator [](int index)
{
	return items[index];	//is passed the index of an element and returns the value at that index in the array that calls this function
}

//overloaded + operator to concactenate two bags after removing duplicates
ArrayBag ArrayBag::operator+(ArrayBag& right)
{
	//adds contents of left hand side of + operator to tempbag, then adds contents of right hand side of + operator to tempbag
	ArrayBag tempbag;
	for (int combine = 0; combine < itemCount; combine++)	//complexity n
	{
		tempbag.add(items[combine]);
	}
	for (int combine2 = 0; combine2 < right.getCurrentSize(); combine2++)	//complexity n
	{
		tempbag.add(right.items[combine2]);
	}

	//scans each item in tempbag for a duplicate item.  If one exists, removes that item.
	for (int selfDuplicate = 0; selfDuplicate < tempbag.getCurrentSize(); selfDuplicate++) //complexity n, scans an element, then in the inner loop, scans each other element in tempbag
	{
		for (int selfInner = 0; selfInner < tempbag.getCurrentSize(); selfInner++)	//complexity quadratic n, total complexity 3n and n^2, so total complexity is n^2 quadratic
		{
			if (tempbag[selfDuplicate] == tempbag[selfInner] && selfDuplicate != selfInner)	//if the value of an element is equal to another element, and their index numbers are different (so not itself)
				tempbag.remove(tempbag[selfInner]);		//removes one of those elements to effectively remove duplicates
		}
	}
	return tempbag;
}

//overloaded - operator to remove the contents of one bag from another
ArrayBag ArrayBag::operator-(ArrayBag& right)
{
	//adds contents of left hand side of - operator to tempbag
	ArrayBag tempbag;
	for (int count = 0; count < itemCount; count++)	//complexity n
	{
		tempbag.add(items[count]);
	}
	//removes contents of right hand side of - operator from tempbag
	for (int count1 = 0; count1 < itemCount; count1++)  //complexity n
	{
		for (int count2 = 0; count2 < right.getCurrentSize(); count2++) //complexity quadratic n, total complexity is 2n and n^2 so quadratic N^2
		{
			if(items[count1] == right[count2])	//if the value of an element in the left hand side of - is equal to the value of an element in the right hand side of an element
				tempbag.remove(items[count1]);
		}
	}
	return tempbag;
}