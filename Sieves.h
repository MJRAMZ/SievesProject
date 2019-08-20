//===================================
// Sieves of Eratosthenes Project
// Created by: MJRAMZ
//===================================


#ifndef SIEVES_H
#define SIEVES_H
#include<iostream>

// QueueNode Template
template <class T> class QueueNode
{
private:
    // Queue Node Value
    T value;
    // Queue Node Pointer -- next node
    QueueNode<T> *next;
    // Queue Node Pointer -- previous node
    QueueNode<T> *prev;

public:
    // Constructor
    QueueNode(T nodeValue)
    {
        // Initialize value and pointers
        value = nodeValue;
        next = nullptr;
        prev = nullptr;
    }

    // Get Next Node
    QueueNode<T> *getNextNode()
    {
        // Return pointer to next node in queue
        return next;
    }

    // Get Previous Node
    QueueNode<T> *getPrevNode()
    {
        // Return pointer to previous node in queue
        return prev;
    }

    // Get Node Value
    T getNodeValue()
    {
        // Return the value of the node
        return value;
    }

    // Set Next Node
    void setNextNode(QueueNode<T> *newNode)
    {
        // Set the next node pointer in the queue
        next = newNode;
    }

    // Set Previous Node
    void setPrevNode(QueueNode<T> *newNode)
    {
        // Set the previous node pointer in the queue
        prev = newNode;
    }

    // Set Node Value
    void setNodeValue(T newValue)
    {
        // Set the node value in the queue
        value = newValue;
    }

}; // End of QueueNode Class


// SievesQueue Template
template <class T> class SievesQueue
{
private:
    // Pointer for the head and tail -- tracks the front and rear of queue
    QueueNode<T> *head, *tail;
    // Integer submitted by user -- used to fill queue
    T maxNum;
    // Number of elements in queue
    int numElements;

public:
    // Constructor
    SievesQueue();
    //-------------------
    // MEMBER FUNCTIONS
    //-------------------
    void display();
    bool isEmpty();
    int getSize();
    T peekFront();
    T peekRear();
    void pushBack(T);
    void enqueue(T);// same as pushBack
    T popFront();
    T dequeue(); // same as pop front
    void fillQueue(T);
};


#endif // SIEVES_H
