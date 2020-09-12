#include "Grad.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Core.h"

double Grad::grade() const { return std::min(thesis, Core::grade()); }
std::istream& Grad::read(std::istream& is) {
  read_common(is);
  read_thesis(is);
  read_hw(is, homework);
  return is;
}

std::istream& Grad::read_thesis(std::istream& is) {
  if (is) {
    is >> thesis;
  }
  return is;
}