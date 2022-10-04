#include <iostream>
#include "./Lista.h"

int main() {
    Lista<int> *list = new Lista<int>;
    list->push(2);
    list->push(4);
    list->push(6);
    list->push(8);
    list->push(10);
    list->push(12);
    list->push(14);
    list->push(16);
    list->print();
    list->delete_front();
    list->print();
    list->delete_back();
    list->print();
    list->delete_index(2);
    list->print();
    return 0;
}