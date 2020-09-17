#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include <string>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

double grade(double&, double&, double);
double grade(double&, double&, std::vector<double>&);
double grade(Student_info&);

#endif // !GUARD_grade_h
