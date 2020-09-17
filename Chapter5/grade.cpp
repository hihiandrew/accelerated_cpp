#include <vector>
#include "grade.h"
#include "median.h"
using namespace std;

double grade(double& midterm, double& final, double hw) {
	return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}

double grade(double& midterm, double& final, vector<double>& homework) {
	return grade(midterm, final, median(homework));
}

double grade(Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}