#include <iostream>

void asd(int *&r) {
  r = new int(10);
}

int main () {
  int *a = new int(8);
  asd(a);
  std::cout << *a << std::endl;
  return 0;
}
