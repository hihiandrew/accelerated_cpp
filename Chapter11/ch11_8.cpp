#include <iostream>

#include "Listy.h"
using std::cout;
using std::endl;

int ch11_8() {
  LList<int> list;
  for (int i = 0; i < 10; i++) {
    list.push_back(i);
  }
  LList<int>::iterator iter = list.begin();
  while (iter != list.end()) {
    cout << *iter++ << endl;
  }
  return 0;
}