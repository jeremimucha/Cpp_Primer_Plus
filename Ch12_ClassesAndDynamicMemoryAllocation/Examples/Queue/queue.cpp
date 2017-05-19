// queue.cpp -- Queue and Customer methods
#include "queue.h"
#include <cstdlib>


// Queue methods

Queue::~Queue()
{
    Node* temp;
    while(front != nullptr){
        temp = front;
        front = front->next;
        delete temp;
    }
}


// Add item to queue
bool Queue::enqueue(const Item& item)
{
    if(isfull())
        return false;

    Node* add = new Node;   // create node
// on failure, new throws std::bad_alloc exception
    add->item = item;
    add->next = nullptr;
    ++items;
    if(front==nullptr)
        front = add;
    else
        rear->next = add;
    rear = add;
    return true;
}

// Place front item into item variable and remove from queue
bool Queue::dequeue(Item& item)
{
    if(front == nullptr)
        return false;
    item = front->item;     // setitem to first item in queue
    --items;
    Node* temp = front;
    front = front->next;
    delete temp;
    if( items == 0 )
        rear = nullptr;
    return true;
}


// customer methods

// when is the time at chiwch teh customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
