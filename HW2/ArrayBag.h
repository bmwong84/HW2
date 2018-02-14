//Bryant Wong CSCi 2421 Homework 2

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.
//Modified by TAA to remove templates and Inheritance

/** ADT bag: Array-based implementation.
 @file ArrayBag.h */


#ifndef BAG_
#define BAG_
#include <iostream>	
#include <vector>	//for toVector
#include <fstream>	//don't think I need this here


typedef int ItemType;
class ArrayBag
{
private:
	static const int DEFAULT_BAG_SIZE = 100;	//max size of bags
	ItemType items[DEFAULT_BAG_SIZE];			 // array of bag items (ItemType are int, array name is "items")
   int itemCount;                    // current count of bag items, (or current number of elements in the array )
   int maxItems;                     // max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   //declaration of function to find the index number of a certain item

public:
	ArrayBag();		//for the class ArrayBag
	int getCurrentSize() const;	//declaration of fucntion to find the number of elements or items in a bag
	bool isEmpty() const;	//declaration of funciton to check if bag is empty
	bool add(const ItemType& newEntry);	//declaration of function to add an item of ItemType, int.  passes the reference of an int
	bool remove(const ItemType& anEntry);	//same as add, but removes
	void clear();	//declaration of funciton to clear (set size to 0) a bag
	bool contains(const ItemType& anEntry) const;	//declaration of a function to check if an item of a passed value exists in the bag
	int getFrequencyOf(const ItemType& anEntry) const;	//declaration of a function to see how many times an item is found in a bag
    std::vector<ItemType> toVector() const;	//declaration of a function that converts all items in a bag into a vector and returns the vector
	void printValues();	//declaration of a function that print outs all of the values of the items in a bag
	ArrayBag operator + (ArrayBag& right) ;  //sets overloaded operator + to perform member function +
	ArrayBag operator - (ArrayBag& right) ;  //sets overloaded operator - to perform member function -
	ItemType operator [] (int index);	//sets overloaded operator [] to perform member function [] to get value of index of the array in this class
}
;  // end Bag
;

#endif
