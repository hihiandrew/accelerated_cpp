#include <list>
using std::list;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Student_info.h"
#include "ch11_5.h"

int ch11_5(){
  vector<Student_info> students_v;
  list<Student_info> students_l; 
  test_calls(students_v);
  test_calls(students_l);
  return 0;
}

