#include <iostream>
#include "./Lista.h"

int main() {
    Lista<int> *list = new Lista<int>;
    //list->push_back_recu(17, list->getHead());
    //list->push_back_iter(12);
    //list->push_back_iter(16);
    list->push_back_iter(15);
    list->push_back_recu(19, list->getHead());
    list->push_back_recu(21, list->getHead());
    list->push_back_recu(23, list->getHead());
    list->print_normal();
    list->delete_index(3);
    list->print_normal();
    list->delete_index(4);
    //list->delete_front();
    //list->delete_back();
    //list->find_iter(13);
    //list->find_iter(19);
    //list->find_recu(13, list->getHead());
    //list->print_reverse_recu(list->getHead());
    //std::cout << list->find_max_iter() << std::endl;
    //std::cout << list->find_max_recu(list->getHead(), list->getHead()->getValue()) << std::endl;
    return 0;
}