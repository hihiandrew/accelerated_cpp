#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <iostream>
using std::istream;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include "grade.h"

class Core {
 public:
  // constructors
  Core() : midterm(0), final(0){};
  Core(std::istream& is) { read(is); };
  // destructor
  //virtual ~Core();
  // accessors 
  virtual std::string name() const { return n; };
  virtual double grade() const { return ::grade(midterm, final, homework); };
  virtual std::istream& read(std::istream&);

 protected:
  // derived classes have access to these private members
  std::istream& read_common(std::istream&);
  std::istream& read_hw(std::istream&, std::vector<double>&);
  std::vector<double> homework;
  double midterm, final;

 private:
  std::string n;
};

// reading utility functions
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

#endif