#include <iostream>
#include "./Lista.h"

int main() {
    Lista *list1 = new Lista;
    Lista *list2 = new Lista;
    Lista *list3 = new Lista;
    list1->push_orden(8, 7);
    list1->push_orden(-1, 0);
    list1->push_orden(-19, 5);
    list1->push_orden(3, 4);
    list1->push_orden(2, 4);
    list1->push_orden(3, 2);
    list1->push_orden(2, 7);
    list1->push_orden(15, 9);
    list1->print();

    list2->push_orden(5, 5);
    list2->push_orden(3, 8);
    list2->push_orden(-15, 9);
    //list2->push_orden(21, 2);
    list2->push_orden(-3, 2);
    list2->print();

    list3->sum_polinomios(list1, list2);
    list3->print();
    return 0;
}