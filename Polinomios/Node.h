#ifndef NODE_H
#define NODE_H

// template <class Type>
class Node
{
private:
    int coeficiente;
    int exponente;
    Node *next;

public:
    Node(int, int);
    ~Node();
    void setCoeficiente(int);
    void setExponente(int);
    void setNext(Node *);
    int getCoeficiente();
    int getExponente();
    Node *getNext();
};

#include "./Node.cpp"

#endif
