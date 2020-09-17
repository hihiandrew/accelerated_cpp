#ifndef GUARD_read_h
#define GUARD_read_h

#include <iostream>
#include <vector>
#include <list>
#include "grade.h"

std::istream& read_record(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
bool fgrade(Student_info&);
bool pgrade(Student_info&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::vector<Student_info> extract_fails_old(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);

#endif // !GUARD_read_h
