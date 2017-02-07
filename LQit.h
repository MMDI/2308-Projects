// File Name: LQit.h
//  
// Author: Robert James Castleberry
// Date: 8/4/2016
// Assignment Number: 5
// CS2308 Summer 2016
// Instructor: Dan Tamir
//
/* LLQueue class specification */
#ifndef LQIT_H
#define LQIT_H
using namespace std;

class LLQueue
{
    private:
        class QueueNode
        {
            friend class LLQueue;
            char letter;
            QueueNode *next;
            QueueNode(char letter1, QueueNode *next1 = NULL)
            {
                letter = letter1;
                next = next1;
            }
        };
        // Track the front and rear of the queue
        QueueNode *front;
        QueueNode *rear;
    public:
        LLQueue() { front = NULL; rear = NULL; }
        ~LLQueue() { clear(); }
        void enqueue(char);
        void dequeue();
        bool isEmpty() const;
        bool isFull() const; // **Pass a string?
        void clear();
        char getFront();
};
#endif
