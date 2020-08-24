#include <string>
#include <vector>

#include <iostream>
using std::istream;

#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include "read.h"

// value-initializing via constructor initializer list
Student_info::Student_info(): midterm(0),finalexam(0){}

// no value-initialization required given read_record immd assigns values
Student_info::Student_info(istream& in){read(in);}

// the data members are accessible directly
istream& Student_info::read(istream& in){
  if(in){
    in >> n >> midterm >> finalexam;
    read_hw(in, homework);
  }
  
  calc_grade(); // member function

  return in;
}


bool compare(const Student_info& x, const Student_info& y){
  return x.name() < y.name();
}


void Student_info::calc_grade() {
  finalgrade = ::grade(midterm,finalexam,homework);
}
