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

int ch6_6() {

	cout << "Please input student grades: " << endl;

	// filter students into two vectors
	Student_info student;
	vector<Student_info> did, didnt;
	while (read_record(cin, student)) {
		if (did_all_hw(student)) {
			did.push_back(student);
		}
		else {
			didnt.push_back(student);
		}
	}

	if (did.empty() || didnt.empty()) {
		cout << "Student behaviour is same across, no analysis possible." << endl;
		return 1;
	}

	write_analysis2(cout, "Median", grade_median, did, didnt);
	write_analysis2(cout, "Average", grade_average, did, didnt);
	write_analysis2(cout, "Optimisic Median", grade_optimistic_median, did, didnt);

	return 0;
}