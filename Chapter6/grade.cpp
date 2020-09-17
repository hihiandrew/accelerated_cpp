#include <vector>
#include "grade.h"
#include "median.h"
#include <stdexcept>
using namespace std;

double grade(const double& midterm,const double& final,const double hw) {
	return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}

double grade(const double& midterm,const double& final,const vector<double>& homework) {
	return grade(midterm, final, median(homework));
}

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}
