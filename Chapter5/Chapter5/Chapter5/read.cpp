#include <iostream>
#include "grade.h"
#include <vector>

using namespace std;

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		hw.clear();
		double x;
		while (in >> x) {
			hw.push_back(x);
		}
		in.clear();
	}
	return in;
}

istream& read_record(istream& in, Student_info& s) {
	if (in) {
		in >> s.name;
		in >> s.midterm;
		in >> s.final;
		read_hw(in, s.homework);
	}
	return in;
}