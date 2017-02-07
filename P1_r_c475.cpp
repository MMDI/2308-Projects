// File Name: P1_r_c475.cpp
// 
// Author: Robert James Castleberry
// Date: 7/18/2016
// Assignment Number: 1
// CS 2308 Summer 2016 
// Instructor: Dan Tamir
//
// Cumulative Weight Pr8-5: 27n - 5
// Theoretical Complexity Pr8-5: O(n^2)
// Cumulative Weight P1_r_c475: arithmetic sequence
// Theoretical Complexity P1_r_c475: O(n^2)
//
// This program uses a sort algorithm to sort an
// array of user input numbers in descending order.

#include <iostream>
using namespace std;

// Function prototypes
int *setNums(int);
void sort(int [], int);
void showArray(int [], int);

int main()
{
	int *nums,  // To point to the numbers
		sizeNums;   // To hold the number of values we want to sort

	// Ask user how many numbers they wants to sort and validate input
	do
    {  
    	cout << "How many numbers would you like to sort? (integer value): ";
    	cin >> sizeNums;
    	
    	if ( sizeNums < 1)
    	{
            cout << "Please enter a positive nonzero integer" << endl;
    	}

	} while (sizeNums < 1);

	// Set an array of user input numbers
	nums = setNums(sizeNums);

	// Sort the array in descending order
	sort(nums, sizeNums);

	// Display sorted values
	cout << "The sorted values are" << endl;
	showArray(nums, sizeNums);

	// Create a pause so the output can be viewed.
	cin.ignore();
	cout << "Press [Enter] to exit the program: " << endl;
	cin.get();
    
    delete [] nums;
    nums = 0;
	return 0;
}


//*
// Function definition for setNums. This function dynamically allocates an array,
// populates it with validated user input, and returns a pointer. 
//* 

int *setNums(int size)
{
	int *array; // Array to hold the user's numbers

	array = new int[size]; // Dynamically allocate the array

	cout << "Enter your numbers below. Integers only please!" << endl;

	// Populate the array with the user's input
	for (int count = 0; count < size; count++)
	{
        cout << "Enter a number (integer): ";
        cin >> array[count];
	}
	//Return a pointer to the array
	return array;
}

//*
// Function definition for sort. The inner loop identifies the minimal value of 
// the array as well as the maximal value of the array in every iteration. The outer 
// loop swaps the maximal value and the minimal value with the appropriate array 
// elements to obtain sorting in a descending order 
//*

void sort(int arr[], int size)
{
	int startScan,
		endScan,
		minIndex,
		minValue,
		maxIndex,
		maxValue;

	for (startScan = 0, endScan = (size -1); (endScan - startScan) >= 1; startScan++, endScan--)
	{
		minIndex = endScan;
		minValue = arr[endScan];
		maxIndex = startScan;
		maxValue = arr[startScan];

		for(int i = (startScan + 1), j = (endScan - 1); (i <= endScan) && (j >= startScan); i++, j--)
      	{
        	if (arr[i] > maxValue)
         	{
            	maxValue = arr[i];
            	maxIndex = i;
         	}
         	 if (arr[j] < minValue)
         	 {
         	 	minValue = arr[j];
         	 	minIndex = j;
         	 }
		}
        
        if (arr[startScan] != maxValue)
        {
           arr[startScan] ^= arr[maxIndex];
           arr[maxIndex] ^= arr[startScan];
           arr[startScan] ^= arr[maxIndex];
        }

        if (arr[endScan] != minValue)
        {
            arr[endScan] ^= arr[minIndex];
            arr[minIndex] ^= arr[endScan];
            arr[endScan] ^= arr[minIndex];
        }
	}
}


//*
// Definition of function showArray.                           
// This function displays the contents of array. size is the   
// number of elements. 
//*                                         

void showArray(int array[], int size)
{
   for (int count = 0; count < size; count++)
      cout << array[count] << " ";
   cout << endl;
}





