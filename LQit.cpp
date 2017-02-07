// File Name: LQit.cpp
//  
// Author: Robert James Castleberry
// Date: 8/4/2016
// Assignment Number: 5
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* LLQueue class implementation */
#include <iostream>
#include "LQit.h"
using namespace std;

/* Function enqueue inserts the letter in ltr
 * at the rear of the queue. */
void LLQueue::enqueue(char ltr)
{
    if (isEmpty())
    {
        front = new QueueNode(ltr);
        rear = front;
    }
    else
    {
        rear->next = new QueueNode(ltr);
        rear = rear->next;
    }
}

/* Function dequeue removes the letter at the
 * front of the queue and copies it into ltr. */
void LLQueue::dequeue()
{
    QueueNode *temp;
    temp = front;
    front = front->next;
    delete temp;
}

/* Function isEmpty returns true if the queue
 * is empty and false otherwise. */
bool LLQueue::isEmpty() const
{
    if (front == NULL)
    {    
        return true;
    }
    else
    {   
        return false;
    }
}

/* Function isFull returns true if the queue
 * is full and false otherwise. */
bool LLQueue::isFull() const
{
    // **Pass string toCheck and divide length by 3 then compare?
}

/* Funtion clear dequeues all the elements
 * in the queue. */
void LLQueue::clear()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

/* Function getFront returns the letter at 
 * the front of the queue. */
char LLQueue::getFront()
{
    char ltrFront;
    ltrFront = front->letter;
    return ltrFront;
}
