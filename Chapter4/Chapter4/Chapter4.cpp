// Chapter4.cpp : Defines the entry point for the application.
//

#include "Chapter4.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ios>

#include "Student_info.h"
#include "grade.h"

using namespace std;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all records, find the length of longest name
	while (read_record(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::size_type i = 0; i < students.size(); i++) {
		// write name and spaces
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

		// compute grade and try write
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);

		}
		catch(domain_error e){
			cout << e.what();
		}
		cout << endl;
	}

	return 0;
}
