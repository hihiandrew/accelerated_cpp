#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include <string>

struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

double grade(const double&, const double&, const double);
double grade(const double&, const double&, const std::vector<double>&);
double grade(const Student_info&);


#endif // !GUARD_grade_h
