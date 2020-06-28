#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <vector>
#include <string>
#include "grade.h"

bool did_all_hw(const Student_info&);
double grade_aux(const Student_info&);
double grade_avg(const Student_info&);
double optimistic_median(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median_analysis(const std::vector<Student_info>&);
void write_analysis(std::ostream&, const std::string&,
	double analysis(const std::vector<Student_info>&),
	const std::vector<Student_info>&,
	const std::vector<Student_info>&);

#endif // !GUARD_analysis_h

