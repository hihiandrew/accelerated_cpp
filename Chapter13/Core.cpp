#include "Core.h"

#include <iostream>
#include <string>
#include <vector>

#include "grade.h"

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

bool compare(const Core& c1, const Core& c2) { return c1.name() < c2.name(); }

bool compare_Core_ptrs(const Core* cp1, const Core* cp2) {
  return compare(*cp1, *cp2);
}
