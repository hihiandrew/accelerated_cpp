#include <iostream>
#include <string>
#include <vector>
#include "Student_info.h"

using std::istream;
using std::vector;

bool compare(const Student_info& a, const Student_info& b) {
	return a.name < b.name;
}

istream& read_record(istream& is, Student_info& s) {

	// read and store first three inputs into Student_info struct
	is >> s.name >> s.midterm >> s.final;

	// read remaining student homework grades
	read_hw(is, s.homework);

	return is;
}

istream& read_hw(istream& is, vector<double>& hw) {

	// if stream already in error state, return that error immd
	if (is) {
		// empty out my output array
		hw.clear();

		// read homework grades
		double x;
		while (is >> x) {
			hw.push_back(x);
		}

		// clear the stream for the next student input
		is.clear();
	}
	return is;
}