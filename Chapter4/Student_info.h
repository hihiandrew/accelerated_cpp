#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	double final, midterm;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read_record(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
#endif