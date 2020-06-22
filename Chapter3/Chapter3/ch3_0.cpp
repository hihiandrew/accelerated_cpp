#include <iostream>
#include <ios>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int ch3_0() {
	// ask for students name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// ask for and read the midterm and final grades;
	cout << "Please enter your mditerm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	// ask for the homework grades
	cout << "Enter all yor homework grades, "
		"followed by end-of-file:";

	// the number an sum of grades read so far
	int count = 0;
	double sum = 0;

	// a variable into which to read
	double x;
	vector<double> homework;

	// invariant
	while (cin >> x) {
		homework.push_back(x);
	}

	// create vec_sz synonym of type, store vector size
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	// error checking for no homework value input
	if (size == 0) {
		cout << endl << "You must enter your grades. "
			"Please try again." << endl;
		return 1;
	}

	// sort homework vector, find median
	sort(homework.begin(), homework.end());
	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2
		: homework[mid];


	// write the result
	streamsize prec = cout.precision(); // used to reset cout precision later on.
	cout << "Your final grade is " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	return 0;
}