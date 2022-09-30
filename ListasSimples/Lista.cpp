#include "./Lista.h"

template <class Type>
Lista<Type>::Lista() {
    this->head = nullptr;
}

template <class Type>
Lista<Type>::~Lista() {
    delete this;
}

template <class Type>
Node<Type> * Lista<Type>::getHead() {
    return this->head;
}

template <class Type>
void Lista<Type>::push_front(Type _value) {
    Node<Type> * newNode = new Node<Type>(_value);
    newNode->setNext(this->head);
    this->head = newNode;
}

template <class Type>
void Lista<Type>::push_back_iter(Type _value) {
    Node<Type> * newNode = new Node<Type>(_value);
    Node<Type> * tempNode = this->head;
    if (tempNode == nullptr) {
        this->head = newNode;
        return;
    }
    while (tempNode->getNext() != nullptr) {
        tempNode = tempNode->getNext();
    }
    tempNode->setNext(newNode);
}

template <class Type>
void Lista<Type>::push_back_recu(Type _value, Node<Type> * _current) {
    if (_current == nullptr) {
        this->head = new Node<Type>(_value);
        return;
    }
    if (_current->getNext() == nullptr) {
        Node<Type> * newNode = new Node<Type>(_value);
        _current->setNext(newNode);
        return;
    } else {
        this->push_back_recu(_value, _current->getNext());
    }
}

template <class Type>
void Lista<Type>::push_index(Type _value, int _index) {
    if (_index < 0) {
        std::cerr << "ERROR: el index es inválido." << std::endl;
        exit(-1);
    }
    Node<Type> * tempNode = this->head;
    if (tempNode == nullptr && _index != 0) {
        std::cerr << "ERROR: La lista está vacía." << std::endl;
        exit(-1);
    }
    if (_index == 0) {
        this->push_front(_value);
        return;
    }
    Node<Type> * newNode = new Node<Type>(_value);
    for (int i = _index - 1; i > 0; --i) {
        if (tempNode == nullptr) {
            std::cerr << "ERROR: El index no existe." << std::endl;
            exit(-1);
        }
        tempNode = tempNode->getNext();
    }
    //std::cout << tempNode->getValue() << std::endl;
    newNode->setNext(tempNode->getNext());
    tempNode->setNext(newNode);
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
    Node<Type> * tempNode = this->head;
    if (tempNode == nullptr) {
        std::cerr << "ERROR: La lista está vacía." << std::endl;
        exit(-1);
    }
    while (tempNode->getNext()->getNext() != nullptr) {
        tempNode = tempNode->getNext();
    }
    Node<Type> * auxNode = tempNode->getNext();
    tempNode->setNext(nullptr);
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
void Lista<Type>::find_iter(Type _value) {
    Node<Type> * tempNode = this->head;
    if (tempNode == nullptr) {
        std::cerr << "ERROR: La lista está vacía." << std::endl;
        exit(-1);
    }
    while (tempNode != nullptr) {
        if (tempNode->getValue() == _value) {
            std::cout << "Valor encontrado." << std::endl;
            return;
        }
        tempNode = tempNode->getNext();
    }
    std::cout << "Valor no encontrado." << std::endl;
    return;
}

template <class Type>
void Lista<Type>::find_recu(Type _value, Node<Type> * _current) {
    if (_current->getValue() == _value) {
        std::cout << "Valor encontrado." << std::endl;
        return;
    }
    if (_current == nullptr) {
        std::cout << "Valor no encontrado." << std::endl;
        return;
    } else {
        this->find_recu(_value, _current->getNext());
    }
}

template <class Type>
void Lista<Type>::print_normal() {
    Node<Type> * tempNode = this->head;
    while (tempNode->getNext() != nullptr) {
        std::cout << tempNode->getValue() << " -> ";
        tempNode = tempNode->getNext();
    }
    std::cout << tempNode->getValue() << std::endl;
}

template <class Type>
void Lista<Type>::print_reverse_recu(Node<Type> * _current) {
    if (_current == nullptr) {
        return;
    }
    this->print_reverse_recu(_current->getNext());
    if (_current == this->head) {
        std::cout << _current->getValue() << std::endl;
    } else {
        std::cout << _current->getValue() << " -> ";
    }
}

template <class Type>
void Lista<Type>::print_reverse_iter() {

}

template <class Type>
Type Lista<Type>::find_max_iter() {
    Node<Type> * tempNode = this->head;
    Type max = tempNode->getValue();
    while (tempNode != nullptr) {
        if (tempNode->getValue() > max) {
            max = tempNode->getValue();
        }
        tempNode = tempNode->getNext();
    }
    return max;
}

template <class Type>
Type Lista<Type>::find_max_recu(Node<Type> * _current, Type _max) {
    if (_current == nullptr) {
        return _max;
    } else {
        if (_current->getValue() > _max) {
            _max = _current->getValue();
        }
        return this->find_max_recu(_current->getNext(), _max);
    }
}