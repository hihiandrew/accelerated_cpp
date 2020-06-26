#ifndef GUARD_read_h
#define GUARD_read_h

#include <iostream>
#include <vector>
#include "grade.h"

std::istream& read_record(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif // !GUARD_read_h
