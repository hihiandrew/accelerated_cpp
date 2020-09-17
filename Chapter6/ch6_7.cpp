#include <algorithm>
#include "grade.h"
#include "read.h"
#include "median.h"
#include "average.h"
#include "analysis.h"

using namespace std;

/*
seperate did and didnt (do homework)
send both vectors into three different analysis:
a. average marking
b. median marking (including zeros')
c. optimistic median marking (ignoring zeros')
*/

vector<Student_info> extract_skip_hw(vector<Student_info>& s) {
	vector<Student_info> didnt;
	vector<Student_info>::iterator iter;
	iter = stable_partition(s.begin(), s.end(), did_all_hw);
	copy(iter, s.end(), back_inserter(didnt));
	s.erase(iter, s.end());
	return didnt;
}

int ch6_7() {

	cout << "Please input student grades: " << endl;

	// filter students into two vectors
	Student_info student;
	vector<Student_info> students;
	while (read_record(cin, student)) {
		students.push_back(student);
	}

	vector<Student_info> did, didnt;
	didnt = extract_skip_hw(students);
	did = students;

	if (did.empty() || didnt.empty()) {
		cout << "Student behaviour is same across, no analysis possible." << endl;
		return 1;
	}

	write_analysis2(cout, "Median", grade_median, did, didnt);
	write_analysis2(cout, "Average", grade_average, did, didnt);
	write_analysis2(cout, "Optimisic Median", grade_optimistic_median, did, didnt);

	return 0;
}