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
// nested template Node
    template<typename V>
    struct Node{
        V val;
        struct Node* next;
        Node()
            : val(), next(nullptr) { }
        Node(const V& v, Node* n=nullptr)
            : val(v), next(n) { }
    };

    void clear();

private:
    Node<T>* head;
    Node<T>* tail;
    
public:
    using forward_iterator = Node<T>*;
    using const_forward_iterator = const Node<T>*;
    QueueTP()
        : head(nullptr), tail(nullptr)
        { std::cout << "--> QueueTP()\n"; }
    QueueTP(const T& t)
        : head(new Node<T>(t)), tail(new Node<T>(t))
        { }
    QueueTP(initializer_list<T> lst)
        : head(nullptr), tail(nullptr)
        {
            for(int i=0; i<lst.size(); ++i){
                Node<T>* node = new Node<T>(lst[i]);
                if(tail == nullptr)
                    head = tail = node;
                else{
                    tail->next = node;
                    tail = tail->next;
                }
            }
        }
    QueueTP(const QueueTP& q)
        : head(nullptr), tail(nullptr)
        {
            for(Node<T>* n=q.begin; n!=nullptr; n = n->next){
                if(tail == nullptr)
                    head = tail = new Node<T>(n->val);
                else{
                    tail->next = new Node<T>(n->val);
                    tail = tail->next;
                }
            }
        }
    QueueTP& operator=(const QueueTP& q);
    ~QueueTP()
        { clear(); }
    forward_iterator begin()
        { return head; }
    const_forward_iterator begin() const
        { return head; }
    forward_iterator end()
        { return tail->next; }
    const_forward_iterator end() const
        { return tail->next; }
    T& last()
        { return tail->val; }
    const T& last() const
        { return tail->val; }
    bool push(const T& v);
    bool pop(T& v);

};

template<typename T>
void QueueTP<T>::clear()
{
    Node<T>* n = head;
    while(n != nullptr){
        Node<T>* temp = n->next;
        delete n;
        n = temp;
    }
    head = tail = nullptr;
}

template<typename T>
QueueTP<T>& QueueTP<T>::operator=(const QueueTP& q)
{
    if( this == &q )
        return *this;

    // destroy all the elements currently in the queue
    clear();    
    // iterate over the q - copy all the node values to new nodes
    for(Node<T>* n=q.head; n!=nullptr; n = n->next){
        if(tail == nullptr){
            head = tail = new Node<T>(n->val);
        }
        else{
            tail->next = new Node<T>(n->val);
            tail = tail->next;
        }
    }
    return *this;
}

template<typename T>
bool QueueTP<T>::push(const T& v)
{
    Node<T>* node = new Node<T>(v);
    if(node == nullptr)
        return false;

    if(head == nullptr)
        head = node;
    else
        tail->next = node;
    tail = node;
    return true;
}

template<typename T>
bool QueueTP<T>::pop(T& v)
{
    if( head != nullptr ){
        v = head->val;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        if( head == nullptr )
            tail = nullptr;
        return true;
    }
    return false;
}

#endif /*QUEUETP_H_*/
