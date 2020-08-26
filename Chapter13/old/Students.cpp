#include "Students.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Core Class Member Functions
bool compare(const Core& c1, const Core& c2) { return c1.name() < c2.name(); }

bool compare_Core_ptrs(const Core* cp1, const Core* cp2) {
  return compare(*cp1, *cp2);
}

std::string Core::name() const { return n; }

double Core::grade() const { return ::grade(midterm, final, homework); }

std::istream& Core::read_common(std::istream& is) {
  is >> n >> midterm >> final;
  return is;
}
std::istream& Core::read_hw(std::istream& is, std::vector<double>& hw) {
  if (is) {
    hw.clear();
    double x;
    while (is >> x) {
      hw.push_back(x);
    }
    is.clear();
  }
  return is;
}
std::istream& Core::read(std::istream& is) {
  read_common(is);
  read_hw(is, homework);
  return is;
}

// Grad Class Member Functions
double Grad::grade() const { return std::min(thesis, Core::grade()); }
std::istream& Grad::read(std::istream& is) {
  read_common(is);
  is >> thesis;
  read_hw(is, homework);
  return is;
}

// Student_info Handler Class Member Functions
Student_info::Student_info(const Student_info& rhs) : cp(0) {
  if (rhs.cp) cp = rhs.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& rhs) {
  if (&rhs != this) {
    delete cp;
    if (rhs.cp)
      cp = rhs.cp->clone();
    else
      cp = 0;
  }
  return *this;
}

std::istream& Student_info::read(std::istream& is) {
  delete cp;
  char ch;
  is >> ch;
  if (ch == 'U')
    cp = new Core(is);
  else if (ch == 'G')
    cp = new Grad(is);
  else
    throw;
  return is;
}

// Comparison and Grading Utility Functions
std::istream& read_hw(std::istream& in, std::vector<double>& hw) {
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

double grade(double midterm, double finalexam, double hw) {
  return 0.2 * midterm + 0.4 * finalexam + 0.4 * hw;
}

double grade(double midterm, double finalexam, const std::vector<double>& hw) {
  if (hw.size() == 0) {
    throw std::domain_error("Student has not done any homework");
  }
  return grade(midterm, finalexam, median(hw));
}
double median(std::vector<double> vec) {
  if (vec.size() == 0) {
    throw std::domain_error("Empty vector supplied to median()");
  }
  sort(vec.begin(), vec.end());
  std::vector<double>::size_type mid = vec.size() / 2;
  return vec.size() % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
