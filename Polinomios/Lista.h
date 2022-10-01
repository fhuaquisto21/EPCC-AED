#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "./Node.h"

class Lista {
    private:
        Node * head;
    public:
        Lista();
        ~Lista();
        Node * getHead();
        void push_front(int, int);
        void push_back(int, int);
        void push_orden(int, int);
        void sum_polinomios(Lista *, Lista *);
        void delete_front();
        void delete_back();
        void print();
};

#include "./Lista.cpp"

#endif