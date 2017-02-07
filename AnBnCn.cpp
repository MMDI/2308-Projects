// File Name: AnBnCn.cpp
//  
// Author: Robert James Castleberry
// Date: 8/4/2016
// Assignment Number: 5
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* This program uses a list based queue class to
 * check if an input string is of the form
 * (a^n)(b^n)(c^n) */
#include <iostream>
#include <string>
#include "LQit.h"
using namespace std;

int main()
{
    string toCheck;
    int size;
    LLQueue cQueue;
    bool valid = true;  // Remains true if the string is valid for testing
    bool flag = false;  // Remains false unless underflow occurs
    
    // Set a string for testing
    cout << "Please enter the string to check: \n";
    cin.sync();
    getline(cin, toCheck);

    size = toCheck.length();

    // Scan the string to validate for testing
    if (toCheck[0] != 'a')
    {
        cout << "Invalid string.\n";
        valid = false;
    }
    else
    {
        for (int i = 1; i < size; i++)
        {
            if ((toCheck[i] != 'a') && (toCheck[i] != 'b'))
            {
                cout << "Invalid String.\n";
                valid = false;
                break;
            }
        }
    }

    // Test the valid string
    if (valid)
    {
        int j = 0;  // To index elements of the string being tested
        
        while ((toCheck[j] == 'a') && (j < size))
        {
            cQueue.enqueue(toCheck[j]);
            j++;
        }
        while ((toCheck[j] == 'b') && (j < size))
        {
            if ((cQueue.isEmpty()) || (cQueue.getFront() != 'a'))
            {
                flag = true;
                break;
            }
            else
            {
                cQueue.dequeue();
                cQueue.enqueue(toCheck[j]);
                j++;
            }
        }
        while ((toCheck[j] == 'a') && (j < size))
        {
            if ((cQueue.isEmpty()) || (cQueue.getFront() != 'b'))
            {
                flag = true;
                break;
            }
            else
            {
                cQueue.dequeue();
                j++;
            }
        }
        // Print results of test
        if ((cQueue.isEmpty()) && (!flag) && (j == size))
        {
            cout << "The string is valid!\n";
        }
        else
        {
            cout << "Invalid string.\n";
        }
    }
 
    return 0;
}
