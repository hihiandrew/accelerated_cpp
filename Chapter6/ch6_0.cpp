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

int ch6_0() {

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

	write_analysis(cout, "Median", median_analysis, did, didnt);
	write_analysis(cout, "Average", average_analysis, did, didnt);
	write_analysis(cout, "Optimisic Median", optimistic_median_analysis, did, didnt);

	return 0;
}