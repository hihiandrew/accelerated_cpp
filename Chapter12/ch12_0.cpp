#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Str.h"

int ch12_0() {
  Str S;
  S = "hello";
  Str W = "world";
  S += W;
  cout << S << endl;

  cout << "Please enter some words: " << endl;
  Str x;
  if (cin >> x) {
    cout << x << endl;
  }
  return 0;
}
