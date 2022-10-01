#include "./Node.h"

Node::Node(int _coeficiente, int _exponente) {
    this->coeficiente = _coeficiente;
    this->exponente = _exponente;
    this->next = nullptr;
}

Node::~Node() {}

void Node::setCoeficiente(int _coeficiente) {
    this->coeficiente = _coeficiente;
}

void Node::setExponente(int _exponente) {
    this->exponente = _exponente;
}

void Node::setNext(Node * _next) {
    this->next = _next;
}

int Node::getCoeficiente() {
    return this->coeficiente;
}

int Node::getExponente() {
    return this->exponente;
}

Node * Node::getNext() {
    return this->next;
}

