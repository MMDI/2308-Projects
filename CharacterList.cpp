// File Name: CharacterList.cpp
//  
// Author: Robert James Castleberry
// Date: 7/24/2016
// Assignment Number: 3
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* This is the implementation file for the CharacterList class*/
#include "CharacterList.h"
using namespace std;

/* Definition of the isPalindrome function. This function
tests whether a list of characters is a palindrome or not.*/
void CharacterList::isPalindrome()
{
    // Initializes pointers and variables needed for the test loop
    ListNode *nodePtr = head;
    ListNode *chasePtr = head;
    ListNode *startPtr = head;
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

/* Definition of getList function. This function prints
 * the data contained in the nodes of the list.*/
void CharacterList::getList()
{
    ListNode *getPtr = head;
    while (getPtr)
    {
        cout << getPtr->data;
        getPtr = getPtr->next;
    }
    cout << endl;
}

/* Definition of setList function. This function 
 * adds a character to the list.*/
void CharacterList::setList(char character)
{
    if (!head)
    {
        head = new ListNode(character);
    }
    else
    {
        ListNode *setPtr = head;
        while (setPtr->next)
        {
            setPtr = setPtr->next;
        }
        setPtr->next = new ListNode(character);
    }
}

/* Destructor deallocates the memory used by the list.*/
CharacterList::~CharacterList()
{
    ListNode *destPtr = head; 
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
