#ifndef GUARD_ch11_5_h
#define GUARD_ch11_5_h

#include <vector>
#include <iostream>
#include "Student_info.h"

template <typename T>
void test_calls(T& students){
  std::cout << "Enter students grades: " << std::endl;
  Student_info::reset_call_count();
  Student_info record;
  std::cin.clear();
  while(record(std::cin)){
    students.push_back(record);
  }
  extract_fails(students);
  Student_info::print_call_count(std::cout);
}

int ch11_5();
#endif
