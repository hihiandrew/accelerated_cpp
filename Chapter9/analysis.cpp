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

double students_analysis(const vector<Student_info>& students, double grader(const Student_info&)) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grader);
	return median(grades);
}

double median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_median);
	return median(grades);
}

double average_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_average);
	return median(grades);
}

double optimistic_median_analysis(const vector<Student_info>& students) {
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_optimistic_median);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
	double analysis(const vector<Student_info>&),
	const vector<Student_info>& did,
	const vector<Student_info>& didnt) {
	out << name << " Analysis: median(did) = " << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}

void write_analysis2(ostream& out, const string& name,
	double grader(const Student_info&),
	const vector<Student_info>& did,
	const vector<Student_info>& didnt) {
	out << name << " Analysis: median(did) = " << students_analysis(did, grader) <<
		", median(didnt) = " << students_analysis(didnt, grader) << endl;
}