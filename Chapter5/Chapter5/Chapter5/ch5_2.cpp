#include "grade.h"
#include "read.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <chrono> 

using namespace std;
using namespace std::chrono;

bool fgrade(Student_info& s) {
	return grade(s) < 60;
}

vector<Student_info> extract_fails_vec(vector<Student_info>& students) {
	vector<Student_info> fail;
	vector <Student_info>::size_type i = 0;
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

list<Student_info> extract_fails_list(list<Student_info>& students) {
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

int ch5_2() {
	cout << "Please enter name and grades: " << endl;
	vector<Student_info> students_vec;
	list<Student_info> students_list;
	Student_info record;
	while (read_record(cin, record)) {
		students_vec.push_back(record);
		students_list.push_back(record);
	}
	auto start = high_resolution_clock::now();
	extract_fails_vec(students_vec);
	auto stop = high_resolution_clock::now();
	auto duration_vec = duration_cast<microseconds>(stop - start);
	cout << "Vector time: " << duration_vec.count() << "." << endl;

	auto start2 = high_resolution_clock::now();
	extract_fails_list(students_list);
	auto stop2 = high_resolution_clock::now();
	auto duration_list = duration_cast<microseconds>(stop2 - start2);
	cout << "List time: " << duration_list.count() << "." << endl;
	
	return 0;
}