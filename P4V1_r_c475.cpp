// File Name: P4V1_r_c475.cpp
//  
// Author: Robert James Castleberry
// Date: 7/28/2016
// Assignment Number: 4
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* This program manages a simple key encryption system for
 * encrypting user input strings*/
#include "KeyManagerV1.h"
#include <iostream>
using namespace std;

int main()
{
    KeyManagerV1 myManager;
    if (myManager.validateKey())
    {
        cout << "\nGOOD KEY EXISTS AND IS IN USE\n";   
    }
    else
    {
        cout << "\nNO VALID KEY EXISTS\n";
        myManager.changeKey();
    }
    myManager.menu();
    
    return 0;
}
