// File Name: CharacterList.h
//  
// Author: Robert James Castleberry
// Date: 7/24/2016
// Assignment Number: 3
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* This is a specification of the CharacterList class*/
#ifndef CHARACTERLIST_H
#define CHARACTERLIST_H
#include <iostream>
using namespace std;

class CharacterList
{
    private:
        struct ListNode
        {
            char data;
            ListNode *next;
            // Constructor
            ListNode(char data1, ListNode *next1 = NULL)
            {
                data = data1;
                next = next1;
            }
        };
        ListNode *head;
    public:
        CharacterList() 
        { 
            head = NULL;
        }
        ~CharacterList();
        void isPalindrome();
        void getList();
        void setList(char); 
};
#endif
