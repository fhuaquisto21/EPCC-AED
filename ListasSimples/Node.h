#ifndef NODE_H
#define NODE_H

template <class Type>
class Node
{
private:
    Type value;
    Node<Type> *next;

public:
    Node(Type);
    ~Node();
    void setValue(Type);
    void setNext(Node<Type> *);
    Type getValue();
    Node<Type> *getNext();
};

#include "./Node.cpp"

#endif
