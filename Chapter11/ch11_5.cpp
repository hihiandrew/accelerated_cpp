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
/*
void test_list_calls(){
  cout << "Enter students grades: " << endl;
  Student_info::reset_call_count();
  vector<Student_info> students_v;
  list<Student_info> students_l;

  Student_info record;
  string s;

  while(record.read(cin)){
    students_v.push_back(record);
  }
  extract_fails(students_v);
  Student_info::print_call_count(cout);
}
*/

int ch11_5(){
  vector<Student_info> students_v;
  list<Student_info> students_l; 
  test_calls(students_v);
  test_calls(students_l);
  return 0;
}

