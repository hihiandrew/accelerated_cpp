#include <vector>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"
#include "median.h"

using std::domain_error;
using std::vector;

// overloading functions..

double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// const reference for efficiency - not editing this vector
double grade(double midterm, double final, const vector<double>& hw) {
	return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}
