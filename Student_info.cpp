#include <string>
#include <vector>
#include <iostream>
#include "Student_info.h"
#include "grade.h"
#include "median.h"
#include "read.h"

Student_info::Student_info(): midterm(0),final(0){}

Student_info::Student_info(istream& is){read(is);}
