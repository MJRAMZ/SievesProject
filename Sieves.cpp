//===================================
// Sieves of Eratosthenes Project
// Created by: MJRAMZ
//===================================

#include "Sieves.h"
#include <cmath>
//******************
// CONSTRUCTOR     *
//******************
template <class T> SievesQueue<T>::SievesQueue()
{
    // Initialize head and tail pointers
    head = nullptr;
    tail = nullptr;
    // Initialize user submitted num
    maxNum = 0;
    // Initialize number of elements in queue to 0
    numElements = 0;

    // Initialize Queues

}

/*****************************************
*		  SievesQueue::display           *
* Displays all node values of the queue. *
******************************************/
template <class T> void SievesQueue<T>::display()
{
    // standard namespace directive
    using namespace std;

    // Make a new node called current
    // Set the "current" pointer to head
    QueueNode<T> *current = head;

    // Check if the "current" pointer is null
    if(current == nullptr)
    {
        // If so, display message that queue is empty
        cout << "The Queue is empty!" << endl;
    }
    else
    {
        // If not empty, loop through the queue
        for(int i=0; i<numElements; i++)
        {
            // Display current node value
            cout << current->getNodeValue() << " ";
            // Set current pointer to next node in queue
            current = current->getNextNode();
            if(current == nullptr) break;
        }
        cout << endl;
    }
}

/*******************************************************
*				SievesQueue::isEmpty                   *
* Returns true if the queue is empty. False otherwise. *
********************************************************/
template <class T> bool SievesQueue<T>::isEmpty()
{
    // create a boolean status variable
	bool status;

	// check the size of the queue
	if (numElements > 0)
		status = false;
	else
		status = true;
	return status;
}

/***************************************************
*				SievesQueue::size                  *
* Returns the number of elements within the queue. *
****************************************************/
template <class T> int SievesQueue<T>::getSize()
{
    // return the number of elements in the queue
    return numElements;
}

/**************************************************
*			SievesQueue::peekFront                *
* Looks at and returns the front value the queue. *
* Does not remove value from queue.               *
***************************************************/
template <class T> T SievesQueue<T>::peekFront()
{
    // Return the head node value
    return head->getNodeValue();
}

/**************************************************
*			SievesQueue::peekRear                 *
* Looks at and returns the rear value the queue.  *
* Does not remove value from queue.               *
***************************************************/
template <class T> T SievesQueue<T>::peekRear()
{
    // Return tail node value
    return tail->getNodeValue();
}

/*************************************************
*			SievesQueue::pushBack                *
* Inserts a node value to the rear of the queue. *
**************************************************/
template <class T> void SievesQueue<T>::pushBack(T newItem)
{
    // Create a new node
    QueueNode<T> *newNode = new QueueNode<T>(newItem);

    // Check if head pointer is null -- empty queue
    if(head == nullptr)
    {
        // set head and tail pointers
        head = newNode;
        tail = newNode;
        // set number of elements to 1
        numElements = 1;
    }
    else
    {
        // Queue is not empty
        // Set tail pointer to new next node
        tail->setNextNode(newNode);
        // set head of new node to the previous node -- old tail
        newNode->setPrevNode(tail);
        // the tail of the new node is now the current tail
        tail = newNode;
        // increment the number of elements in the queue
        numElements++;
    }
}

/********************************
*	  SievesQueue::enqueue      *
* Calls the pushBack function.  *
*********************************/
template <class T> void SievesQueue<T>::enqueue(T newItem)
{
    // Add new item to the rear of the queue
    pushBack(newItem);
}

/****************************************************
*			SievesQueue::popFront                   *
* Removes a node value from the front of the queue. *
*****************************************************/
template <class T> T SievesQueue<T>::popFront()
{
    // Check if the queue is empty
    if(numElements > 0)
    {
        // Save the front node value
        T value = head->getNodeValue();
        // Create a new node -- old head
        // Set the old head pointer to the current head
        QueueNode<T> *oldHead = head;
        // Set the current head pointer to the next node
        head = head->getNextNode();
        // Set the old head pointer to null
        oldHead->setNextNode(nullptr);
        // Check if the head pointer is not null
        if(head != nullptr)
        {
            // Set head's previous node pointer to null
            head->setPrevNode(nullptr);
        }
        // Decrement the elements in the queue
        numElements--;
        // remove front value
        delete oldHead;
        // return node value
        return value;
    }
    return (T)nullptr;
}

/********************************
*	  SievesQueue::dequeue      *
* Calls the popFront function.  *
*********************************/
template <class T> T SievesQueue<T>::dequeue()
{
    // Remove node value from the front
    return popFront();
}

/********************************************************
*	               SievesQueue::fillQueue               *
* Fills an empty queue with consecutive integers 2 through N.  *
*********************************************************/
template <class T> void SievesQueue<T>::fillQueue(T num)
{
    // set maxNum to user submitted integer value
    maxNum = num;

    // Fill the queue
    for(int i=2; i <= maxNum; i++)
    {
        // add integers to queue
        enqueue(i);
    }
}


