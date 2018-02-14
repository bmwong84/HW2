//Bryant Wong CSCi 2421 Homework 2

#include "SetFunctions.h"	//needed for class
#include "ArrayBag.h"	//needed for returning a new bag of arrays after operations carried out
#include <sstream>      //stringstream needed for integer check
#include <string>		//needed for string readString
#include <iostream>	



//from validateinput.cpp Dr. Augustine 09/02/2016 modified to add the int to a bag instead of a vector
bool getIntsFromFile(std::ifstream &infile, ArrayBag& bag)	//accepts the file and names it to the local variable name infile, accepts ArrayBag with local variable name bag
//istream accepts from cin or file as a parent class
{
	std::stringstream ss;
	int tempInt;
	std::string readString;

	getline(infile, readString);		//reads the file until it encounters a newline character
	ss << readString; //Write readString into ss
	while (!ss.eof()) //Until end of stream
	{
		ss >> tempInt; //Read in an int from ss into tempInt
		if (ss.fail()) //If it fails to to read an int data type
		{
			std::cout << "Input contains non-integer data\n";
			ss.clear(); //Clears state of string stream;
			return false;
		}
		bag.add (tempInt); //Add item to the bag
	}
	return true;
}


