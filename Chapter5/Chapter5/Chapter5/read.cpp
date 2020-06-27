#include <iostream>
#include "grade.h"
#include <vector>
#include <list>

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

bool fgrade(Student_info& s) {
	return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;
	while (i != students.size()) {
		if (fgrade(students[i])) {
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else {
			i++;
		}
	}
	return fail;
}

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else {
			++iter;
		}
	}
	return fail;
}