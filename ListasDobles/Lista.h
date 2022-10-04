#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "./Node.h"

template <class Type>
class Lista {
    private:
        Node<Type> * head;
        Node<Type> * last;
    public:
        Lista();
        ~Lista();
        Node<Type> * getHead();
        void push(Type);
        void delete_front();
        void delete_back();
        void delete_index(int);
        void print();
};

#include "./Lista.cpp"

#endif