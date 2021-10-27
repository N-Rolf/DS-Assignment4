/********************************************************************
***  NAME       :Neil Rolf       ***
***  CLASS      :CSc 300         ***
***  ASSIGNMENT :Assignment 4    ***
***  DUE DATE   :10/18/2021      ***
***  INSTRUCTOR :  GAMRADT       ***
*********************************************************************
***  DESCRIPTION :Queue ADT implemented with linked list   ***
********************************************************************/
#include "Queue.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;


/********************************************************************
***  FUNCTION Queue                                            ***
*********************************************************************
***  DESCRIPTION   : This is the constructor for the queue        ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

Queue::Queue(short size=2):Q_SIZE{size}
{
    queue = new QElement[Q_SIZE];
    head = 0;
    tail = 0;
}

/********************************************************************
***  FUNCTION Queue(Queue & old)                            ***
*********************************************************************
***  DESCRIPTION   : This is the copy constructor for the queue   ***
***  INPUT ARGS    : pointer to a Queue object                 ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/


Queue::Queue(Queue & old) : head(old.head),tail(old.tail),Q_SIZE(old.Q_SIZE)
{
    cout << "Copying..." << endl;

    QElement element;
    queue = new QElement[old.Q_SIZE];

    while(old.head != NULL){
        //element = old.dequeue;
        // temp.enqueue(element);
        // same as ^^
        enqueue(old.dequeue());
        }

}

/********************************************************************
***  FUNCTION ~Queue                                           ***
*********************************************************************
***  DESCRIPTION   : This is the destructor for the queue         ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
Queue::~Queue()
{
    cout << "Destroying..." << endl;

    while(head != NULL){
        dequeue();
        }

    delete queue;

}

/********************************************************************
***  FUNCTION enqueue                                          ***
*********************************************************************
***  DESCRIPTION   : This function ands a new Element to our Queue,
***                : which is passed in from the driver           ***
***  INPUT ARGS    : const Element                             ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
void Queue::enqueue(const QElement enqueue)
{
    if(isFull())
        {
            cout << "Stack is full. Cannot add." << endl;
            return;
        }
    
    int index = head;

    while(queue[index] != NULL)
    {
        index++;
    }
    queue[index] = enqueue;

    if(tail == Q_SIZE-1)
        {
            tail = 0;
        }
        else
        {
            tail++;
        }

}

/********************************************************************
***  FUNCTION dequeue                                          ***
*********************************************************************
***  DESCRIPTION   : This function removes a QElement from the     ***
***                : front of the queue also test is queue is empty***
***  INPUT ARGS    : QElement                                   ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
QElement Queue::dequeue()
{
    if(isEmpty())
        {
            cout << "Stack is empty. Cannot delete." << endl;
            return;
        }
    
    QElement temp = queue[head];
    queue[head] = NULL;
    if(head == Q_SIZE-1)
    {
        head = 0;
    }
    else
    {
        head++;
    }
    
    return temp;
}

/********************************************************************
***  FUNCTION view                                                ***
*********************************************************************
***  DESCRIPTION   : This displays the queue from front to rear   ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

void Queue::view()
{
    short i = head;

    cout << "HEAD";

    while(i != tail)
    {
        cout << "->" << queue[i];
        if(i == Q_SIZE-1)
        {
            i=0;
        }
        else
        {
            i++;
        }
    }
    cout << "TAIL" << endl;

}

/********************************************************************
***  FUNCTION isFull                                                ***
*********************************************************************
***  DESCRIPTION   : This displays the queue from front to rear   ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
bool Queue::isFull() const
{
    bool isFull = true;
    
    for(int i=0; i < Q_SIZE; i++)
    {
        if(queue[i] == NULL)
        {
            isFull = false;
        }
    }

    return isFull;
}

/********************************************************************
***  FUNCTION isEmpty                                                ***
*********************************************************************
***  DESCRIPTION   : This displays the queue from front to rear   ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
bool Queue::isEmpty() const 
{
    
    bool isEmpty = true;
    
    for(int i=0; i < Q_SIZE; i++)
    {
        if(queue[i] != NULL)
        {
            isEmpty = false;
        }
    }

    return isEmpty;
}