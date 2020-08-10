#include <iostream>

#include "Vec.h"
using std::cout;
using std::endl;

int ch11_6() {
  Vec<int> vec;
  for (int i = 1; i < 11; i++) {
    vec.push_back(i);
  }
  vec.print_vec(cout);

  int* res = vec.erase(vec.begin() + 5);
  vec.print_vec(cout);
  cout << *res << endl;

  int* res2 = vec.erase(vec.begin(), vec.begin() + 3);
  vec.print_vec(cout);
  cout << *res2 << endl;

  vec.clear();
  vec.push_back(4);
  vec.print_vec(cout);

  return 0;
}
