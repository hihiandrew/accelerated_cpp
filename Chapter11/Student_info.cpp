#include <list>
using std::list;

#include <vector>
using std::vector;

#include <stdexcept>
using std::domain_error;

#include <algorithm>
using std::sort;

#include <iostream>
using std::endl;
using std::istream;
using std::ostream;

#include "Student_info.h"

int Student_info::default_constructor_calls;
int Student_info::stream_constructor_calls;
int Student_info::copy_constructor_calls;
int Student_info::assignment_operator_calls;
int Student_info::destructor_calls;

// value-initializing via constructor initializer list
Student_info::Student_info() : midterm(0), finalexam(0) {
  ++default_constructor_calls;
}

// no value-initialization required given read_record immd assigns values
Student_info::Student_info(istream& in) {
  ++stream_constructor_calls;
  read(in);
}

// copy constructor
Student_info::Student_info(const Student_info& s) {
  ++copy_constructor_calls;
  n = s.n;
  homework = s.homework;
  midterm = s.midterm;
  finalexam = s.finalexam;
}

// assignment operator
Student_info& Student_info::operator=(const Student_info& rhs) {
  ++assignment_operator_calls;
  if (this != &rhs) {
    homework = rhs.homework;
    midterm = rhs.midterm;
    finalexam = rhs.finalexam;
  }
  return *this;
}

// destructor
Student_info::~Student_info() { ++destructor_calls; }

istream& Student_info::read(istream& in) {
  if (in) {
    in >> n >> midterm >> finalexam;
    read_hw(in, homework);
  }

  calc_grade();  // member function

  return in;
}

void Student_info::calc_grade() {
  finalgrade = ::grade(midterm, finalexam, homework);
}

istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    hw.clear();
    double x;
    while (in >> x) {
      hw.push_back(x);
    }
    in.clear();
  }
  return in;
}

void Student_info::reset_call_count() {
  default_constructor_calls = 0;
  stream_constructor_calls = 0;
  copy_constructor_calls = 0;
  assignment_operator_calls = 0;
  destructor_calls = 0;
}

ostream& Student_info::print_call_count(ostream& os) {
  os << default_constructor_calls << '\t' << "default constructor calls"
     << endl;
  os << stream_constructor_calls << '\t' << "stream constructor calls" << endl;
  os << copy_constructor_calls << '\t' << "copy constructor calls" << endl;
  os << assignment_operator_calls << '\t' << "assignment calls" << endl;
  os << destructor_calls << '\t' << "destructor calls" << endl;
  return os;
}

double grade(const double& midterm, const double& final, const double hw) {
  return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}

double grade(const double& midterm, const double& final,
             const vector<double>& homework) {
  return grade(midterm, final, median(homework));
}

double median(vector<double> vec) {
  if (vec.size() == 0) {
    throw domain_error("empty vector supplied to median()");
  }
  sort(vec.begin(), vec.end());
  vector<double>::size_type mid = vec.size() / 2;
  return vec.size() % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

bool compare(const Student_info& x, const Student_info& y) {
  return x.name() < y.name();
}

bool pgrade(const Student_info& s) { return s.get_grade() >= 60; }

bool fgrade(const Student_info& s) { return !pgrade(s); }

vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
  students.erase(remove_if(students.begin(), students.end(), fgrade),
                 students.end());
  return fail;
}

list<Student_info> extract_fails(list<Student_info>& students) {
  list<Student_info> fail;
  list<Student_info>::iterator iter = students.begin();
  while (iter != students.end()) {
    if (fgrade(*iter)) {
      fail.push_back(*iter);
      iter = students.erase(iter);
    } else {
      ++iter;
    }
  }
  return fail;
}
