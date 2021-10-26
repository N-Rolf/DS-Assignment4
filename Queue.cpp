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
using namespace std;


/********************************************************************
***  FUNCTION Queue300                                            ***
*********************************************************************
***  DESCRIPTION   : This is the constructor for the queue        ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

Queue300::Queue300():front(NULL),rear(NULL)
{




}

/********************************************************************
***  FUNCTION Queue300(Queue300 & old)                            ***
*********************************************************************
***  DESCRIPTION   : This is the copy constructor for the queue   ***
***  INPUT ARGS    : pointer to a Queue300 object                 ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/


Queue300::Queue300(Queue300 & old):front(NULL),rear(NULL)
{

Element300 element;

Queue300 temp;
while(old.front != NULL){
     old.deQueue300(element);
    temp.enQueue300(element);

    }
while(temp.rear != NULL){

    temp.deQueue300(element);
    enQueue300(element);
    old.enQueue300(element);

    }

}

/********************************************************************
***  FUNCTION ~Queue300                                           ***
*********************************************************************
***  DESCRIPTION   : This is the destructor for the queue         ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
Queue300::~Queue300()
{

while(rear != NULL){
    deQueue300(front->element);
    }


}

/********************************************************************
***  FUNCTION enQueue300                                          ***
*********************************************************************
***  DESCRIPTION   : This function ands a new element300 to our Queue,
***                : which is passed in from the driver           ***
***  INPUT ARGS    : const Element300                             ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
void Queue300::enQueue300(const Element300 enQueue)
{

NodePtr300 temp = new (std::nothrow) Node300;
if( temp!= NULL)
{
    strcpy(temp->element, enQueue);
    temp->next = NULL;
    if(front == NULL){
    rear = temp;
    front = temp;
    }

    else{
        rear->next = temp;
        rear = temp;
    }

    rear->next = NULL;
    temp =  NULL;
}

}

/********************************************************************
***  FUNCTION DeQueue300                                          ***
*********************************************************************
***  DESCRIPTION   : This function removes a element from the     ***
***                : front of the queue also test is queue is empty***
***  INPUT ARGS    : Element300                                   ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/
void Queue300::deQueue300(Element300 element)
{

if(front != NULL){
    strcpy(element,front->element);
    NodePtr300 temp = NULL;
    temp = front;
    front = front->next;
    temp->next = NULL;
    temp = NULL;
    delete temp;

        if(front == NULL){
            rear = NULL;
            }
    }
else{
    cout<<"Queue empty from deQueue300"<<endl;
    }

}

/********************************************************************
***  FUNCTION view300                                             ***
*********************************************************************
***  DESCRIPTION   : This displays the queue from front to rear   ***
***  INPUT ARGS    : none                                         ***
***  OUTPUT ARGS   : none                                         ***
***  IN/OUT ARGS   : none                                         ***
***  RETURN        : none                                         ***
********************************************************************/

void Queue300::view300()
{

Element300 element;

Queue300 temp ;
cout<<"FRONT->";
while(rear != NULL){

    deQueue300(element);
    cout<<element<<"->";
    temp.enQueue300( element);

    }

while(temp.rear != NULL){
      temp.deQueue300(element);
    enQueue300(element);

    }
cout<<"REAR"<<endl;

}