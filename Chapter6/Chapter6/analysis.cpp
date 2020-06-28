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

double grade_aux(const Student_info& s) {
	try {
		return grade(s);
	}
	catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

double grade_avg(const Student_info& s) {
	return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median(const Student_info& s) {
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

double median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

double average_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_avg);
	return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
	double analysis(const vector<Student_info>&),
	const vector<Student_info>& did,
	const vector<Student_info>& didnt) {
	out << name << " Analysis: median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}