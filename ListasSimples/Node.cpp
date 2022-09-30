#include "./Node.h"

template <class Type>
Node<Type>::Node(Type _value) {
    this->value = _value;
    this->next = nullptr;
}

template <class Type>
Node<Type>::~Node() {}

template <class Type>
void Node<Type>::setValue(Type _value) {
    this->value = _value;
}

template <class Type>
void Node<Type>::setNext(Node * _next) {
    this->next = _next;
}

template <class Type>
Type Node<Type>::getValue() {
    return this->value;
}

template <class Type>
Node<Type> * Node<Type>::getNext() {
    return this->next;
}

