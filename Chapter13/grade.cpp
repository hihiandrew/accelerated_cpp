#include <vector>
using std::vector;

#include <stdexcept>
using std::domain_error;

#include "grade.h"
#include "median.h"


double grade(double midterm, double finalexam, double hw) {
	return 0.2 * midterm + 0.4 * finalexam + 0.4 * hw;
}

double grade(double midterm, double finalexam,const std::vector<double>& hw) {
  if(hw.size() == 0){
    throw domain_error("Student has not done any homework");
  }
	return grade(midterm, finalexam, median(hw));
}
