#include "./Lista.h"

Lista::Lista() {
    this->head = nullptr;
}

Lista::~Lista() {
    delete this;
}

Node * Lista::getHead() {
    return this->head;
}

void Lista::push_front(int _coeficiente, int _exponente) {
    Node * newNode = new Node(_coeficiente, _exponente);
    newNode->setNext(this->head);
    this->head = newNode;
}

void Lista::push_back(int _coeficiente, int _exponente) {
    Node * newNode = new Node(_coeficiente, _exponente);
    Node * tempNode = this->head;
    if (tempNode == nullptr) {
        this->head = newNode;
        return;
    }
    while (tempNode->getNext() != nullptr) {
        tempNode = tempNode->getNext();
    }
    tempNode->setNext(newNode);
}

void Lista::push_orden(int _coeficiente, int _exponente) {
    Node * newNode = new Node(_coeficiente, _exponente);
    Node * tempNode = this->head;
    if (tempNode == nullptr) {
        this->head = newNode;
        return;
    }
    if (tempNode->getExponente() < newNode->getExponente()) {
        newNode->setNext(tempNode);
        this->head = newNode;
        return;
    } else if (tempNode->getExponente() == newNode->getExponente()) {
        if (tempNode->getCoeficiente() + newNode->getCoeficiente() == 0) {
            this->delete_front();
            delete newNode;
            return;
        }
        tempNode->setCoeficiente(tempNode->getCoeficiente() + newNode->getCoeficiente());
        delete newNode;
        return;
    }
    while (tempNode->getNext() != nullptr) {
        if (tempNode->getNext()->getExponente() < newNode->getExponente()) {
            break;
        } else if (tempNode->getNext()->getExponente() == newNode->getExponente()) {
            if (tempNode->getNext()->getCoeficiente() + newNode->getCoeficiente() == 0) {
                Node *aux2 = tempNode->getNext();
                tempNode->setNext(aux2->getNext());
                delete aux2;
                delete newNode;
                return;
            }
            tempNode->getNext()->setCoeficiente(tempNode->getNext()->getCoeficiente() + newNode->getCoeficiente());
            delete newNode;
            return;
        }
        tempNode = tempNode->getNext();
    }
    if (tempNode->getNext() != nullptr) {
        Node * aux = tempNode->getNext();
        tempNode->setNext(newNode);
        newNode->setNext(aux);
        return;
    }
    tempNode->setNext(newNode);
}

void Lista::sum_polinomios(Lista * pol1, Lista * pol2) {
    Node * aux1 = pol1->getHead();
    Node * aux2 = pol2->getHead();
    while (aux1 != nullptr) {
        this->push_orden(aux1->getCoeficiente(), aux1->getExponente());
        aux1 = aux1->getNext();
    }
    while (aux2 != nullptr) {
        this->push_orden(aux2->getCoeficiente(), aux2->getExponente());
        aux2 = aux2->getNext();
    }
}

void Lista::delete_front() {
    if (this->head == nullptr) {
        std::cerr << "ERROR: La lista está vacía." << std::endl;
        exit(-1);
    }
    Node * auxNode = this->head;
    this->head = this->head->getNext();
    delete auxNode;
}

void Lista::delete_back() {
    Node * tempNode = this->head;
    if (tempNode == nullptr) {
        std::cerr << "ERROR: La lista está vacía." << std::endl;
        exit(-1);
    }
    while (tempNode->getNext()->getNext() != nullptr) {
        tempNode = tempNode->getNext();
    }
    Node * auxNode = tempNode->getNext();
    tempNode->setNext(nullptr);
    delete auxNode;
}

void Lista::print() {
    Node * tempNode = this->head;
    std::cout << tempNode->getCoeficiente() << "x" << "^" << tempNode->getExponente() << " ";
    tempNode = tempNode->getNext();
    while (tempNode != nullptr) {
        if (tempNode->getCoeficiente() > 0) {
            std::cout << "+";
        } else {
            std::cout << "-";
        }
        if (tempNode->getCoeficiente() < 0) {
            if (tempNode->getCoeficiente() == 1 && tempNode->getExponente() != 1) {
                std::cout << " " "x" << "^" << tempNode->getExponente() * -1 << " ";
            } else if (tempNode->getCoeficiente() == 1 && tempNode->getExponente() == 1) {
                std::cout << " " << "x" << " ";
            } else if (tempNode->getCoeficiente() != 1 && tempNode->getExponente() == 1) {
                std::cout << " " << tempNode->getCoeficiente() * -1 << "x" << " ";
            } else if (tempNode->getCoeficiente() != 1 && tempNode->getExponente() == 0) {
                std::cout << " " << tempNode->getCoeficiente() * -1 << " ";
            } else {
                std::cout << " " << tempNode->getCoeficiente() * -1 << "x" << "^" << tempNode->getExponente() << " ";
            }
        } else {
            if (tempNode->getCoeficiente() == 1 && tempNode->getExponente() != 1) {
                std::cout << " " "x" << "^" << tempNode->getExponente() << " ";
            } else if (tempNode->getCoeficiente() == 1 && tempNode->getExponente() == 1) {
                std::cout << " " << "x" << " ";
            } else if (tempNode->getCoeficiente() != 1 && tempNode->getExponente() == 1) {
                std::cout << " " << tempNode->getCoeficiente() << "x" << " ";
            } else if (tempNode->getCoeficiente() != 1 && tempNode->getExponente() == 0) {
                std::cout << " " << tempNode->getCoeficiente() << " ";
            } else {
                std::cout << " " << tempNode->getCoeficiente() << "x" << "^" << tempNode->getExponente() << " ";
            }
        }
        tempNode = tempNode->getNext();
    }
    std::cout << std::endl;
    //std::cout << tempNode->getValue() << std::endl;
}