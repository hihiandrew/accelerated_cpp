#include <string>
#include <vector>
#include <iostream>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include "read.h"

Student_info::Student_info(): midterm(0),final(0){}
// no value-initialization required given read_record immd assigns values
Student_info::Student_info(istream& is){read_record(is);}

bool compare(const Student_info& x, const Student_info& y){
  return x.name() < y.name();
}


