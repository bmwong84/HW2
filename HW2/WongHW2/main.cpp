//Bryant Wong CSCI 2421 Homework 2

#include "SetFunctions.h"	
#include "ArrayBag.h"
#include <fstream>	//needed to read files
#include <iostream>	//needed for cout		
using namespace std;


int main()
{
	//creates an array Bag1, Bag2 of type ArrayBag
	ArrayBag Bag1;
	ArrayBag Bag2;
	//from validateInput.cpp Dr. Augustine last updated 09/02/2016, modified to add items to container ArrayBag
	ifstream infile("setInput.txt");	//attempts to open and read contents of file "setInput.txt"
	/*
	if ( infile.is_open() == false ) {
		std::cout << "Error opening file." << std::endl;		test code; used when "setInput.txt" was in the wrong directory
		return 0;
	}
	*/

	if (getIntsFromFile(infile, Bag1))	//calls function getIntsFromFile, passing the read contents of infile and Object/Array Bag1
	{
		cout << "Bag 1 contents: " << endl;
		Bag1.printValues();	//calls member function printValues() to print out the values on screen
	}
	if (getIntsFromFile(infile, Bag2))
	{
		cout << "Bag 2 contents: " << endl;
		Bag2.printValues();
	}
	//if (getIntsFromFile(infile, Bag1) && getIntsFromFile(infile, Bag2))
	//{
		ArrayBag Bag3;	//creates an array Bag3 of type ArrayBag
		Bag3 = Bag1 + Bag2;		//uses overloaded + operator to concactenate Bag1 and Bag2 into Bag 3
		cout << "Bag 3 (union) contents: " << endl; 
		Bag3.printValues();	
		ArrayBag Bag4;
		Bag4 = Bag1 - Bag2;
		cout << "Bag 4 (difference) contents: " << endl;
		Bag4.printValues();
	//}
	cin.get();	//pauses output screen until any key is hit so user can see output if using visual studio
	return 0;
}