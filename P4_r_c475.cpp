// File Name: P4_r_c475.cpp
//  
// Author: Robert James Castleberry
// Date: 7/28/2016
// Assignment Number: 4
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* This program manages a simple key encryption system for
 * encrypting user input strings*/
#include "KeyManager.h" 
using namespace std;

int main()
{
    KeyManager myManager;
    myManager.ValidateKey();
    myManager.menu();
    
    return 0;
}
