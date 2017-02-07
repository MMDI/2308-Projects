// File Name: P6_r_c475.cpp 
//  
// Author: Robert James Castleberry
// Date: 8/13/2016
// Assignment Number: 6
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* Extra credit assignment. My modified quickSort and partition functions
 * use pointers for accessing values per the instructions. I use the [] 
 * operator directly on the vector when printing in the main function to 
 * show that this method also works for accessing values. Also, the vectors
 * are sorted in ascending order as specified. */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Function prototypes
int partition(vector<int>*, int, int);
void quickSort(vector<int>*, int, int);

// Main function tests the modified quickSort
int main()
{
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};  // Initializes array of values to copy
    vector<int> *vectPtr; // Declares a pointer to a vector

    // Declares a vector and copies the values of arr into the vector
    vector<int> vect;
    vect.push_back(7);
    vect.push_back(2);
    vect.push_back(1);
    vect.push_back(6);
    vect.push_back(8);
    vect.push_back(5);
    vect.push_back(3);
    vect.push_back(4);

    // Assigns the address of vect to our pointer for passing to quickSort
    vectPtr = &vect;

    cout << "The unsorted vector is \n";
    for (int i = 0; i < 8; i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;

    
    // Sort vect
    quickSort(vectPtr, 0, 7);

    // Prints vect to show that quickSort works the same with vectors
    cout << "The sorted vector is \n";
    for (int i = 0; i < 8; i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;

    // Now test it on some different input
    vect.clear();
    vect.push_back(23);
    vect.push_back(12);
    vect.push_back(7);
    vect.push_back(1);
    vect.push_back(43);
    vect.push_back(17);
    vect.push_back(11);
    vect.push_back(32);
    vectPtr = &vect;
    
    cout << "The unsorted vector is \n";
    for (int i = 0; i < 8; i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
    
    quickSort(vectPtr, 0, 7);
    
    cout << "The sorted vector is \n";
    for (int i = 0; i < 8; i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
    
    // Test one more set of input to be sure
    vect.clear();
    vect.push_back(88);
    vect.push_back(77);
    vect.push_back(66);
    vect.push_back(55);
    vect.push_back(44);
    vect.push_back(33);
    vect.push_back(22);
    vect.push_back(11);
    vectPtr = &vect;
    
    cout << "The unsorted vector is \n";
    for (int i = 0; i < 8; i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
    
    quickSort(vectPtr, 0, 7);
    
    cout << "The sorted vector is \n";
    for (int i = 0; i < 8; i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;

    return 0;
}

// Function definition for partition
int partition(vector<int> *ptr, int start, int end)
{
    int pivot = (*ptr)[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if ((*ptr)[i] <= pivot)
        {
            swap((*ptr)[i], (*ptr)[pIndex]);
            pIndex++;
        }
    }

    swap ((*ptr)[pIndex], (*ptr)[end]);
    return pIndex;
}

// Function definition for quickSort
void quickSort(vector<int> *ptr, int start, int end)
{
    if (start < end)
    {
        int pIndex = partition(ptr, start, end);
        quickSort(ptr, start, pIndex - 1);
        quickSort(ptr, pIndex + 1, end);
    }
}
