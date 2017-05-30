// queuetp.h -- Chapter 14 pe3 - Queue template
#ifndef QUEUETP_H_
#define QUEUETP_H_

#include <iostream>
#include <initializer_list>
using std::initializer_list;


template<typename T>
class QueueTP
{
protected:
    template<typename T>
    struct Node{
        T val;
        struct Node* next;
        Node()
            : val(), next(nullptr) { }
        Node(const T& v, Node* n=nullptr)
            : val(v), next(n) { }
    };
    void clear();
private:
    Node<T>* head;
    Node<T>* tail;
public:
    QueueTP()
        : head(nullptr), tail(nullptr)
        { std::cout << "--> QueueTP()\n"; }
    QueueTP(const T& t)
        : being(new Node(t)), tail(new Node(t))
    QueueTP(initializer_list<T> lst)
        : head(nullptr), tail(nullptr)
        {
            for(int i=0; i<lst.size(); ++i){
                Node* node = new Node(lst[i]);
                if(tail == nullptr)
                    head = tail = node;
                else{
                    tail->next = node;
                    tail = tail->next;
                }
            }
        }
    QueueTP(const QueueTP& q)
        : head(nullptr), end(nullptr)
        {
            for(Node* n=q.begin; n!=nullptr; n = n->next){
                if(tail == nullptr)
                    head = tail = new Node(n->val);
                else{
                    tail->next = new Node(n->val);
                    tail = tail->next;
                }
            }
        }
    QueueTP& operator=(const QueueTP& q);
    ~QueueTP();
    Node* begin()
        { return head; }
    const Node* begin() const
        { return head; }
    Node* end()
        { return tail->next; }
    const Node* end() const
        { return tail->next; }
    Node* last()
        { return tail; }
    const Node* last() const
        { return last; }
    bool push(const T& v);
    bool pop(T& v);

};

void QueueTP:clear()
{
    Node* n = head;
    while(n != nullptr){
        Node* temp = n->next;
        delete n;
        n = temp;
    }
    head = tail = nullptr;
}

template<typename T>
QueueTP& QueueTP::operator=(const QueueTP& q)
{
    if( this == &q )
        return *this;

    clear();    // destroy all the elements currently in the queue
    // iterate over the q - copy all the node values to new nodes
    for(Node* n=q.begin; n!=nullptr; n = n->next){
        if(tail == nullptr){
            being = tail = new Node(n->val);
        }
        else{
            tail->next = new Node(n->val);
            tail = tail->next;
        }
    }

    return *this;
}

bool QueueTP::push(const T& v)
{
    Node* node = new Node(v);
    if(node == nullptr)
        return false;

    if(tail == nullptr)
        begin = tail = node;
    else{
        tail->next = node;
        tail = tail->next;
    }
    return true;
}

bool QueueTP::pop(T& v)
{
    if( begin != nullptr ){
        v = begin->val;
        
    }
}

#endif /*QUEUETP_H_*/
