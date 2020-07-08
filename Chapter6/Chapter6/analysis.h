#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <vector>
#include <string>
#include <algorithm>
#include "grade.h"

bool did_all_hw(const Student_info&);

double grade_median(const Student_info&);
double grade_average(const Student_info&);
double grade_optimistic_median(const Student_info&);

double students_analysis(const std::vector<Student_info>&);
double median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);

void write_analysis(std::ostream&, const std::string&,
	double analysis(const std::vector<Student_info>&),
	const std::vector<Student_info>&,
	const std::vector<Student_info>&);

void write_analysis2(std::ostream&, const std::string&,
	double grader(const Student_info&),
	const std::vector<Student_info>&,
	const std::vector<Student_info>&);

template <class F>
double students_analysis2(const std::vector<Student_info>& students, F grader) {
	std::vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grader);
	return median(grades);
}

template <class F>
void write_analysis3(std::ostream& out, const std::string& name, F grader,
	const std::vector<Student_info>& did, const std::vector<Student_info>& didnt) {
	out << name << " Analysis: median(did) = " << students_analysis2(did, grader) <<
		", median(didnt) = " << students_analysis2(didnt, grader) << endl;

}


#endif // !GUARD_analysis_h

