#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "./Node.h"

template <class Type>
class Lista {
    private:
        Node<Type> * head;
    public:
        Lista();
        ~Lista();
        Node<Type> * getHead();
        void push_front(Type);
        void push_back_iter(Type);
        void push_back_recu(Type, Node<Type> *);
        void push_index(Type, int);
        void delete_front();
        void delete_back();
        void delete_index(int);
        void find_iter(Type);
        void find_recu(Type, Node<Type> *);
        void print_normal();
        void print_reverse_recu(Node<Type> *);
        void print_reverse_iter();
        Type find_max_iter();
        Type find_max_recu(Node<Type> *, Type);
};

#include "./Lista.cpp"

#endif