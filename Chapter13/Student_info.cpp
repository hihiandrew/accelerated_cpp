#include "Student_info.h"

#include <iostream>
#include <string>
#include <vector>

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
  if (ch == 'U'){
    cp = new Core(is);
  }else{
    cp = new Grad(is);
  }
  return is;
}

bool Student_info::complete() { return cp->complete(); }

std::string Student_info::letter_grade(double grade) {
  // initialize grades
  static const double numbers[] = {97, 94, 90, 87, 82, 80, 77, 74, 70, 60, 0};
  // initialize letters
  static const char* const letters[] = {"A+", "A", "A-", "B+", "B", "B-",
                                        "C+", "C", "C-", "D",  "F"};
  // size of letters[]
  static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
  // calc grade
  for (size_t i = 0; i < ngrades; ++i) {
    if (grade >= numbers[i]) {
      return letters[i];
    }
  }
  return "?\?\?";
}