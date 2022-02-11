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
#include <string>
using namespace std;

/********************************************************************
***  FUNCTION Queue                                               ***
*********************************************************************
***  DESCRIPTION   : This is the constructor for the queue        ***
***  INPUT ARGS    : optional size value                          ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

Queue::Queue(short size) : Q_SIZE{size}
{
    queue = new QElement[Q_SIZE];
    head = -1;
    tail = -1;
    numItems = 0;
}

/********************************************************************
***  FUNCTION Queue(Queue & old)                                  ***
*********************************************************************
***  DESCRIPTION   : This is the copy constructor for the queue   ***
***  INPUT ARGS    : pointer to a Queue object                    ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

Queue::Queue(Queue &old) : head(old.head), tail(old.tail), Q_SIZE(old.Q_SIZE), numItems(old.numItems)
{
    cout << "Copying..." << endl;

    QElement element;
    queue = new QElement[old.Q_SIZE];

    for (int count = 0; count < Q_SIZE; count++)
    {
        queue[count] = old.queue[count];
    }
}

/********************************************************************
***  FUNCTION ~Queue                                              ***
*********************************************************************
***  DESCRIPTION   : This is the destructor for queue objects     ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
Queue::~Queue()
{
    cout << "Destroying..." << endl;

    // while(head != NULL)
    // {
    //     cout << "dequeueing for destruction..." << endl;
    //     dequeue();
    // }

    delete[] queue;
}

/********************************************************************
***  FUNCTION enqueue                                             ***
*********************************************************************
***  DESCRIPTION   : This function adds a new Element to the Queue,
***                : which is passed in from the driver           ***
***  INPUT ARGS    : const string element                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
void Queue::enqueue(const QElement value)
{
    //cout << "EQ Starting head postition: " << head << endl;
    //cout << "EQ Starting tail postition: " << tail << endl;
    
    if (isFull())
    {
        cout << "Stack is full. Cannot add." << endl;
        return;
    }
    else
    {
        
        // if (tail == Q_SIZE - 1)
        // {
        //     tail = 0;
        // }
        // else
        // {
        //     tail++;
        // }
        tail = (tail+1) % Q_SIZE;
        queue[tail] = value;
        //cout << "Enqueueing " << queue[tail] << " at " << tail << " position." << endl;
        numItems++;
    }

    //cout << "EQ Ending head postition: " << head << endl;
    //cout << "EQ Ending tail postition: " << tail << endl;
}

/********************************************************************
***  FUNCTION dequeue                                             ***
*********************************************************************
***  DESCRIPTION   : This function removes a QElement from the    ***
***                : front of the queue, tests if queue is empty  ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : String type element                          ***
********************************************************************/
QElement Queue::dequeue()
{
    //cout << "DQ Starting head postition: " << head << endl;
    //cout << "DQ Starting tail postition: " << tail << endl;

    QElement temp = queue[head];

    if (isEmpty())
    {
        cout << "Stack is empty. Cannot delete." << endl;
    }
    else
    {
        
        // if (head == Q_SIZE - 1)
        // {
        //     head = 0;
        // }
        // else
        // {
        //     head++;
        // }
        head = (head+1) % Q_SIZE;
        temp = queue[head];
        numItems--;
    }
    // cout << "Dequeueing " << temp << "..." << endl;
    //cout << "DQ Ending head postition: " << head << endl;
    //cout << "DQ Ending tail postition: " << tail << endl;
    return temp;
}

/********************************************************************
***  FUNCTION view                                                ***
*********************************************************************
***  DESCRIPTION   : Displays the queue from front to rear        ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

void Queue::view()
{
    if (head == tail)
        {
            cout << "Zero elements in Queue. Cannot view." << endl;
            return;
        }
    
    if (head == 4)
        head = 0;
    if (tail == 0)
        tail = Q_SIZE;
    short i = head;
    //cout << "View Starting head postition: " << head << endl;
    //cout << "View Starting tail postition: " << tail << endl;
    cout << "HEAD";

    while (i != tail)
    {
        cout << "->" << queue[i];
        if (i == Q_SIZE)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }
    cout << "->TAIL" << endl;
    //cout << "View Ending head postition: " << head << endl;
    //cout << "View Ending tail postition: " << tail << endl;
}

/********************************************************************
***  FUNCTION isFull                                              ***
*********************************************************************
***  DESCRIPTION   : Tests for a full queue                       ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : boolean value                                ***
********************************************************************/
bool Queue::isFull() const
{
    bool isFull = true;

    if (numItems < Q_SIZE)
        isFull = false;

    return isFull;
}

/********************************************************************
***  FUNCTION isEmpty                                             ***
*********************************************************************
***  DESCRIPTION   : Tests for an empty queue                     ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : boolean value                                ***
********************************************************************/
bool Queue::isEmpty() const
{

    bool isEmpty = true;

    if (numItems)
        isEmpty = false;

    return isEmpty;
}