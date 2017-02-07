// File Name: P3Extra_r_c475.cpp
//  
// Author: Robert James Castleberry
// Date: 7/24/2016
// Assignment Number: 3
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* This is the extra credit version of P3 that 
 * uses classes.The relevant specification,
 * implementation, and make files have been zipped
 * together with this file*/ 

#include "CharacterList.h"
using namespace std;

int main()
{
    // Declares class objects for use in testing
    CharacterList list;
    CharacterList list1;
    CharacterList list2;
    CharacterList list3;

    // Tests an empty list
    cout << "First, we will test an empty list:" << endl;
    list.isPalindrome();
    cout << "Press [Enter] to continue: " << endl;
    cin.get();

    // Tests a singleton: "a"
    cout << "Next we will test a singleton:" << endl;
    list.setList('a');
    list.getList();
    list.isPalindrome();
    cout << "Press [Enter] to continue: " << endl;
    cin.get();

    // Builds palindrome with an even number of elements: "abba"
    list.setList('b');
    list.setList('b');
    list.setList('a');
    // Tests a palindrome with an even number of elements: "abba"
    cout << "Now, we will test a palindrome with an even number of elements:" << endl;
    list.getList();
    list.isPalindrome();
    cout << "Press [Enter] to continue: " << endl;
    cin.get();
    
    // Bulds a palindrome with an odd number of elements: "abcba"
    list1.setList('a');
    list1.setList('b');
    list1.setList('c');
    list1.setList('b');
    list1.setList('a');
    // Tests a palindrome with an odd number of elements: "abcba"
    cout << "Now, we will test a palindrome with an odd number of elements:" << endl;
    list1.getList();
    list1.isPalindrome();
    cout << "Press [Enter] to continue: " << endl;
    cin.get();

    // Builds a non-palindrome with an even number of elements: "abcd"
    list2.setList('a');
    list2.setList('b');
    list2.setList('c');
    list2.setList('d');
    // Tests a non-palindrome with an even number of elements: "abcd"
    cout << "Now, we will test a non-palindrome with an even number of elements:" << endl;
    list2.getList();
    list2.isPalindrome();
    cout << "Press [Enter] to continue: " << endl;
    cin.get();
    
    // Builds a non-palindrome with an odd number of elements: "abcde"
    list2.setList('e');
    // Tests a non-palindrome with an odd number of elements: "abcde"
    cout << "Now, we will test a non-palindrome with an odd number of elements:" << endl;
    list2.getList();
    list2.isPalindrome();
    cout << "Press [Enter] to continue: " << endl;
    cin.get();

    return 0;
}
