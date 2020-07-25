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
  cout << *res << endl;
  vec.print_vec(cout);

  int* res2 = vec.erase(vec.begin(), vec.begin() + 3);
  cout << *res2 << endl;
  vec.print_vec(cout);

  return 0;
}
