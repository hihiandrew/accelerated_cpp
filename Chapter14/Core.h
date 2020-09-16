#ifndef GUARD_Core_h
#define GUARD_Core_h

#include <iostream>
#include <string>
#include <vector>

#include "grade.h"

class Core {
  friend class Student_info;
  template <class T>
  friend class Handle;

 public:
  // constructors
  Core() : midterm(0), final(0){};
  Core(std::istream& is) { read(is); };
  // destructor made virtual for the purpose of handles class
  // delete cp knowing which synthesize destructor to run
  virtual ~Core(){};
  // accessors
  virtual std::string name() const { return n; };
  virtual double grade() const { return ::grade(midterm, final, homework); };
  virtual std::istream& read(std::istream&);
  virtual bool complete() const { return !homework.empty(); };

 protected:
  // handle class assignment/copy requires clone functionality
  virtual Core* clone() { return new Core(*this); };
  // derived classes have access to these private members
  std::istream& read_common(std::istream&);
  std::istream& read_hw(std::istream&, std::vector<double>&);
  std::vector<double> homework;
  double midterm, final;

 private:
  std::string n;
};

bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);

#endif