#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <iostream>
#include <string>
#include <vector>

#include "Core.h"
#include "Grad.h"

class Student_info {
 public:
  // constructors
  Student_info() : cp(0){};
  Student_info(std::istream& is) : cp(0) { read(is); };
  Student_info(const Student_info& rhs) : cp(0) {
    if (rhs.cp) cp = rhs.cp->clone();
  };
  // destructor
  ~Student_info() { delete cp; }
  // operators
  Student_info& operator=(const Student_info&);
  // utility
  bool valid() const { return !cp->homework.empty(); }
  bool complete();
  std::istream& read(std::istream&);
  std::string name() const {
    if (cp)
      return cp->name();
    else
      throw std::runtime_error("uninitialised Student");
  }
  double grade() const {
    if (cp)
      return cp->grade();
    else
      throw std::runtime_error("uninitialised Student");
  }
  std::string letter_grade(double grade);
  static bool compare(const Student_info& a, const Student_info& b) {
    return a.name() < b.name();
  }

 private:
  Core* cp;
};

#endif
