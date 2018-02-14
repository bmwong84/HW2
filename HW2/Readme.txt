*******************************************************
*  Name      :      Bryant Wong    
*  Student ID:      107571009           
*  Class     :  CSC 2421           
*  HW#       :  2              
*  Due Date  :  Feb 1, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program is supposed to read a series of integers, separated by a newline, into separate sets in an ArrayBag container.
The two sets are to be checked for duplicates and have them removed, then the two sets are to be concactenated together 
using an overloaded + operator and the result printed out.  
Then, all of the values from the second set are to be removed from the first set using an overloaded - operator 
and the result printed out.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This creates the classes full of integers Bag1-4, calls a function to input integers from a file, 
then concactenates Bag1 and Bag2 using the overloaded + operator and calls a function to print the result, then 
removes elements of Bag2 from Bag 1 and calls a function to print the result.


Name:  ArrayBag.h
   Contains the definition for the class ArrayBag.

Name: ArrayBag.cpp
   Contains multiple member functions manipulating the class ArrayBag including size of a class instance,
adding and removing items, and the overloaded operators that are used.

Name: SetFunctions.cpp
  Contains the function to add series of integers from a file to bags.

Name: SetFunctions.h
  Contains the declaration of the function to add a series of integers from a file to bags.
   
   
*******************************************************
*  Circumstances of programs
*******************************************************
The program is complete and compiles and runs on visual studio and csegrid.
	
Developed on Visual Studio Community 2015 14.0.25431.01 Update 3.



*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [WongHW2]

   Now you should see a directory named homework with the files:
        main.cpp
	SetFunctions.cpp
	SetFunctions.h
	ArrayBag.cpp
	ArrayBag.h
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [WongHW2] 

    Compile the program by:
    % make

3. Run the program by:
   % ./hw2

4. Delete the obj files, executables, and core dump by
   %./make clean
