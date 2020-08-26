#include "Grad.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Core.h"

double Grad::grade() const { return std::min(thesis, Core::grade()); }
std::istream& Grad::read(std::istream& is) {
  read_common(is);
  is >> thesis;
  read_hw(is, homework);
  return is;
}