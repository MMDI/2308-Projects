// File Name: P3_r_c475.cpp
//  
// Author: Robert James Castleberry
// Date: 7/24/2016
// Assignment Number: 3
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* This program builds linked lists of characters and
 * tests if they constitute palindromes.*/

#include <iostream>
using namespace std;

// Declare a structure for list nodes
struct ListNode
{
    char data;
    ListNode *next;
};

// Function prototypes
void isPalindrome(ListNode *);
void showList(ListNode *);
void destList(ListNode *);

int main()
{
    ListNode *head = NULL;
    ListNode *charPtr;

    // Tests an empty list
    cout << "First, we will test an empty list:" << endl;
    isPalindrome(head);
    cout << "Press [Enter] to continue: " << endl;
    cin.get();

    // Tests a singleton
    cout << "Next we will test a singleton:" << endl;
    head = new ListNode;
    head->data = 'a';
    head->next = NULL;
    showList(head);
    isPalindrome(head);
    destList(head);
    cout << "Press [Enter] to continue: " << endl;
    cin.get();

    // Builds palindrome with an even number of elements: "abba"
    head = new ListNode;
    charPtr = head;
    charPtr->data = 'a';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'b';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'b';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'a';
    charPtr->next = NULL;
    // Tests a palindrome with an even number of elements: "abba"
    cout << "Now, we will test a palindrome with an even number of elements:" << endl;
    showList(head);
    isPalindrome(head);
    destList(head);
    cout << "Press [Enter] to continue: " << endl;
    cin.get();
    
    // Bulds a palindrome with an odd number of elements: "abcba"
    head = new ListNode;
    charPtr = head;
    charPtr->data = 'a';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'b';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'c';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'b';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'a';
    charPtr->next = NULL;
    // Tests a palindrome with an odd number of elements: "abcba"
    cout << "Now, we will test a palindrome with an odd number of elements:" << endl;
    showList(head);
    isPalindrome(head);
    destList(head);
    cout << "Press [Enter] to continue: " << endl;
    cin.get();

    // Builds a non-palindrome with an even number of elements: "abcd"
    head = new ListNode;
    charPtr = head;
    charPtr->data = 'a';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'b';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'c';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'd';
    charPtr->next = NULL;
    // Tests a non-palindrome with an even number of elements: "abcd"
    cout << "Now, we will test a non-palindrome with an even number of elements:" << endl;
    showList(head);
    isPalindrome(head);
    destList(head);
    cout << "Press [Enter] to continue: " << endl;
    cin.get();
    
    // Builds a non-palindrome with an odd number of elements: "abcde"
    head = new ListNode;
    charPtr = head;
    charPtr->data = 'a';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'b';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'c';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'd';
    charPtr->next = new ListNode;
    charPtr = charPtr->next;
    charPtr->data = 'e';
    charPtr->next = NULL;   
    // Tests a non-palindrome with an odd number of elements: "abcde"
    cout << "Now, we will test a non-palindrome with an odd number of elements:" << endl;
    showList(head);
    isPalindrome(head);
    destList(head);
    cout << "Press [Enter] to continue: " << endl;
    cin.get();

    return 0;
}

/* Definition of the isPalindrome function. This function
tests whether a list of characters is a palindrome or not.*/
void isPalindrome(ListNode *list)
{
    // Initializes pointers and variables needed for the test loop
    ListNode *nodePtr = list;
    ListNode *chasePtr = list;
    ListNode *startPtr = list;
    bool test = true ;

    // Checks the list of chars from the outside ends working inward
    while ((startPtr!= NULL) && (startPtr->next != NULL))
    {
        // Finds the last node
        nodePtr = startPtr;
        while (nodePtr->next != NULL)
        {   
            chasePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        // Checks the first and last characters for mismatch
        if (startPtr->data != nodePtr->data)
        {
            test = false;
            break;  // Ends the loop when a mismatch is found
        }
        // Removes first and last characters from the next iteration if they match
        else
        {
            startPtr = startPtr->next;
            chasePtr->next = NULL;
        }
    }

    if (test)
    {
        cout << "(TRUE) - The list of chars tested is a palindrome." << endl;
    }
    else
    {
        cout << "(FALSE) - The list of chars tested is NOT a palindrome." << endl;
    }
}

// Definition of showList
void showList(ListNode *showPtr)
{
    while (showPtr)
    {
        cout << showPtr->data;
        showPtr = showPtr->next;
    }
    cout << endl;
}

// Definition of destList. This function destroys a list.
void destList(ListNode *destPtr)
{
    while (destPtr)
    {
        // Keeps track of node to be destroyed 
        ListNode *garbage = destPtr;
        // Moves on to the next node, if any
        destPtr = destPtr->next;
        // Deletes the "garbage" node
        delete garbage;
    }
}
