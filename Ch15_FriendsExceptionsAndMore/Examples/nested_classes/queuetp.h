// queuetp.h -- queue template with a nested class
#ifndef QUEUETP_H_
#define QUEUETP_H_


template<typename Item>
class QueueTP
{
private:
    enum {Q_SIZE = 10};
    
    // Node is a nested class definition
    class Node
    {
    public:
        Item item;
        Node* next;
        Node(const Item& i)
            : item(i), next(nullptr) { }
    };
    
    Node* front;        // pointer to front of Queue
    Node* rear;         // pointer to rear of Queue
    int items;          // current number of items in Queue
    const int qsize;    // maximum number of items in Queue
    QueueTP(const QueueTP& q)
        : qsize(0) { }
    QueueTP& operator=(const QueueTP& q) { return *this; }

public:
    QueueTP(int qs=Q_SIZE);
    ~QueueTP();
    bool isempty() const
        { return items == 0; }
    bool isfull() const
        { return items == qsize; }
    int queuecount() const
        { return items; }
    bool enqueue(const Item& item);     // add item to end
    bool dequeue(Item& item);           // remove item from front
};

// QueueTP methods
template<typename Item>
QueueTP<Item>::QueueTP(int qs)
    : front(nullptr), rear(nullptr), items(0), qsize(qs)
{
}

template<typename Item>
QueueTP<Item>::~QueueTP()
{
    Node* temp;
    while(front != nullptr){    // while queue is not yet empty
        temp = front;           // save address of front item
        front = front->next;    // reset pointer to next item
        delete temp;            // delete former front
    }
}

// Add items to queue
template<class Item>
bool QueueTP<Item>::enqueue(const Item& item)
{
    if(isfull())
        return false;
    Node* add = new Node(item);     // create node
// on failure, new throws std::bad_alloc exception
    ++items;
    if(front == 0)      // if queue is empty
        front = add;    // place new item at front
    else
        rear->next = add;
    rear = add;
    return true;
}

// Place front item into item variable and remove from queue
template<typename Item>
bool QueueTP<Item>::dequeue(Item& item)
{
    if(front == nullptr)
        return false;
    item = front->item;     // set item to first item in queue
    --items;
    Node* temp = front;     // save location of first item
    front = front->next;    // reset front to next item
    delete temp;
    if(items == 0)
        rear = 0;
    return true;
}


#endif /*QUEUETP_H_*/
