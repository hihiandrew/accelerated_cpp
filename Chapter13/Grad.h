#ifndef GUARD_Grad_h
#define GUARD_Grad_h

#include <iostream>
#include <string>
#include <vector>
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

 protected:
  // handle class assignment/copy requires clone functionality
  Core* clone() override { return new Core(*this); };

 private:
  double thesis;
};

#endif