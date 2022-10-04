#include "./Lista.h"

template <class Type>
Lista<Type>::Lista() {
    this->head = nullptr;
    this->last = nullptr;
}

template <class Type>
Node<Type> * Lista<Type>::getHead() {
    return this->head;
}

template <class Type>
void Lista<Type>::push(Type _value) {
    Node<Type> * newNode = new Node<Type>(_value);
    newNode->setNext(this->head);
    if (this->head != nullptr) {
        this->head->setPrev(newNode);
    } else {
        this->last = newNode;
    }
    this->head = newNode;
    if (this->head != nullptr && this->head->getNext() == nullptr) {
        this->last->setPrev(this->head);
    }
}

template <class Type>
void Lista<Type>::delete_front() {
    if (this->head == nullptr) {
        std::cerr << "ERROR: La lista está vacía." << std::endl;
        exit(-1);
    }
    Node<Type> * auxNode = this->head;
    this->head = this->head->getNext();
    delete auxNode;
}

template <class Type>
void Lista<Type>::delete_back() {
    if (this->last == nullptr) {
        std::cerr << "ERROR: La lista está vacía." << std::endl;
        exit(-1);
    }
    Node<Type> * auxNode = this->last;
    this->last->getPrev()->setNext(nullptr);
    this->last = this->last->getPrev();
    delete auxNode;
}

template <class Type>
void Lista<Type>::delete_index(int _index) {
    if (_index < 0) {
        std::cerr << "ERROR: el index es inválido." << std::endl;
        exit(-1);
    }
    Node<Type> * tempNode = this->head;
    if (tempNode == nullptr && _index == 0) {
        std::cerr << "ERROR: La lista está vacía." << std::endl;
        exit(-1);
    }
    if (_index == 0) {
        this->delete_front();
        return;
    }
    for (int i = _index - 1; i > 0; --i) {
        if (tempNode->getNext() == nullptr) {
            std::cerr << "ERROR: El index no existe." << std::endl;
            exit(-1);
        }
        tempNode = tempNode->getNext();
    }
    Node<Type> * auxNode = tempNode->getNext();
    tempNode->setNext(tempNode->getNext()->getNext());
    delete auxNode;
}

template <class Type>
void Lista<Type>::print() {
    Node<Type> * tempNode = this->head;
    while (tempNode->getNext() != nullptr) {
        std::cout << tempNode->getValue() << " <-> ";
        tempNode = tempNode->getNext();
    }
    std::cout << tempNode->getValue() << std::endl;
}