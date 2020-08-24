#ifndef GUARD_Grad_h
#define GUARD_Grad_h

#include <iostream>
using std::istream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>

#include "Core.h"

class Grad : public Core {
 public:
  // constructors
  Grad() : thesis(0){};
  Grad(std::istream& is) { read(is); };
  // destructor is inherited
  // accessors
  double grade() const override;
  std::istream& read(std::istream&) override;

 private:
  double thesis;
};

double Grad::grade() const {
  return std::min(thesis,Core::grade());
}
std::istream& Grad::read(std::istream& is){
  read_common(is);
  is >> thesis;
  read_hw(is, homework);
  return is;
}

#endif