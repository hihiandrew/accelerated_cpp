#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "grade.h"
#include "median.h"
#include "average.h"

using namespace std;

bool did_all_hw(const Student_info& s) {
	return find(s.homework.begin(), s.homework.end(), 0) == s.homework.end();
}

double grade_median(const Student_info& s) {
	try {
		return grade(s);
	}
	catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

double grade_average(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

double grade_optimistic_median(const Student_info& s) {
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(),
		back_inserter(nonzero), 0);
	if (nonzero.empty()) {
		return grade(s.midterm, s.final, 0);
	}
	else {
		return grade(s.midterm, s.final, median(nonzero));
	}
}
