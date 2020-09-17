#include <iostream>

#include "Student_info.h"
using std::cin;
using std::cout;
using std::endl;

int ch13_2() {
  Core* p1 = new Core;
  std::cout << "--------\n";
  Core* p2 = new Grad;
  std::cout << "--------\n";
  Core s1;
  std::cout << "--------\n";
  Grad s2;
  std::cout << "--------\n";

  p1->read(cin);
  p2->read(cin);
  s1.read(cin);
  s2.read(cin);

  std::cout << "--------\n";
  p1->grade();
  std::cout << "--------\n";
  p1->name();
  std::cout << "--------\n";
  p2->grade();
  std::cout << "--------\n";
  p2->name();
  std::cout << "--------\n";
  s1.grade();
  std::cout << "--------\n";
  s1.name();
  std::cout << "--------\n";
  s2.name();
  std::cout << "--------\n";
  s2.grade();
  std::cout << "--------\n";

  delete p1;
  delete p2;
  return 0;
}
