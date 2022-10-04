#ifndef NODE_H
#define NODE_H

template <class Type>
class Node
{
private:
    Type value;
    Node<Type> *next;
    Node<Type> *prev;

public:
    Node(Type);
    ~Node();
    void setValue(Type);
    void setNext(Node<Type> *);
    void setPrev(Node<Type> *);
    Type getValue();
    Node<Type> *getNext();
    Node<Type> *getPrev();
};

#include "./Node.cpp"

#endif
