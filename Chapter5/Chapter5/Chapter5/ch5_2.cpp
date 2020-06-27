#include "grade.h"
#include "read.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <list>
#include <string>
#include <chrono> 

using namespace std;
using namespace std::chrono;

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
	extract_fails(students_vec);
	auto stop = high_resolution_clock::now();
	auto duration_vec = duration_cast<microseconds>(stop - start);
	cout << "Vector time: " << duration_vec.count() << "." << endl;

	auto start2 = high_resolution_clock::now();
	extract_fails(students_list);
	auto stop2 = high_resolution_clock::now();
	auto duration_list = duration_cast<microseconds>(stop2 - start2);
	cout << "List time: " << duration_list.count() << "." << endl;
	
	streamsize prec = cout.precision();
	cout << "List is " << setprecision(5)
		<< duration_vec.count() / duration_list.count()
		<< " times faster." << setprecision(prec);
	return 0;
}