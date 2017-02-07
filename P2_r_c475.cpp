// Filename: P2_r_c475.cpp
// 
// Author: Robert James Castleberry
// Date 7/21/2016
// Assignment Number: 2
// CS 2308 Summer 2016
// Instructor: Dan Tamir
//
/* This program uses linked lists instead of arrays in an effort to meet Professor Tamir's 
 * extra credit criteria. The program builds a linked list of user input size and  
 * integer values. It then performs a bubbles sort on the linked list resulting in
 * an ascending order. The user is then asked for input to build a second linked list
 * which is appended to the end of the original list. Both parts of the assignment are 
 * contained within this program rather than two separate programs, which was discussed in 
 * class 7-22-16*/ 

#include <iostream>
using namespace std;

// Structure definition for ListNode
struct ListNode
{
    int value;
    ListNode *next;
    // Constructor
    ListNode(int value1, ListNode *next1 = NULL)
    {
        value = value1;
        next = next1;
    }
};

// Function prototypes
void showList(ListNode *);

int main()
{
    int size,  // To hold the number of values the user wants to sort
        temp,  // Used during swap when sorting the list
        num;  // To store user input
    ListNode *numList = NULL;  // List of numbers
    ListNode *iappend  = NULL;  // List of numbers we will append to the first list
    ListNode *nodePtr; // Used to traverse the list
    ListNode *chasePtr; // Used for sorting the list
    bool swap;  // Used to determine end of bubble sort
    
    // Get list size
    cout << "Please enter only integer values below." << endl;
    do
    {
        cout << "How many numbers would you like to sort? ";
        cin >> size;

        if (size < 1)
        {
            cout << "Please enter a positive nonzero integer" << endl;
        }
    } while (size < 1);

    // Get numbers
    for (int count = 0; count < size; count++)
    {
        cout << "Enter a number: ";
        cin >> num;

        // Check if list is empty
        if (!numList)
        {
            numList = new ListNode(num);    
        }
        else
        {    
            // Find the last node
            nodePtr = numList;
            while (nodePtr->next != NULL)
            {
                nodePtr = nodePtr->next;
            }
            // Point to next new node and pass user input
            nodePtr->next = new ListNode(num);
        }
    }
    
    //Print unsorted list
    cout << "Your unsorted numbers are:" << endl;
    showList(numList);
    
   // Sort the list 
   do
    {
        // Start at the head 
        nodePtr = numList->next ;
        chasePtr = numList;    
        // Reset flag
        swap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (chasePtr->value > nodePtr->value)
            {
                temp = chasePtr->value;
                chasePtr->value = nodePtr->value;
                nodePtr->value = temp;
                swap = true;
            }

            if (nodePtr->next)
            {
                chasePtr = chasePtr->next;
                nodePtr = nodePtr->next;
            }
        }
    } while (swap);

    // Print sorted list
    cout << "Your sorted numbers are:" << endl;
    showList(numList);
        
    // Now we will append another list to the end of our sorted list
    do
    {
        cout << "How many numbers would you like to add to the end of the list? ";
        cin >> size;

        if (size < 1)
        {
            cout << "Please enter a positive nonzero integer" << endl;
        }
    } while (size < 1);

    // Get numbers to append
    for (int count = 0; count < size; count++)
    {
        cout << "Enter a number: ";
        cin >> num;

        // Check if list is empty
        if (!iappend)
        {
            iappend = new ListNode(num);    
        }
        else
        {    
            // Find the last node
            nodePtr = iappend;
            while (nodePtr->next != NULL)
            {
                nodePtr = nodePtr->next;
            }
            // Point to next new node and pass user input
            nodePtr->next = new ListNode(num);
        }
    }
    
    // Find the last node in numList
    nodePtr = numList;
    while (nodePtr->next != NULL)
    {
        nodePtr = nodePtr->next;
    }
    // Append our new list to the end of numList
    nodePtr->next = iappend;

    // Print appended list
    cout << "Your appended list of numbers is:" << endl;
    showList(numList);

    return 0;
}

// Definition of showList
void showList(ListNode *head)
{
    ListNode *nodePtr = head;
    while (nodePtr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}
