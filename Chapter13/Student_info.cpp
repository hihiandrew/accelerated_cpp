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
  if (ch == 'U')
    cp = new Core(is);
  else if (ch == 'G')
    cp = new Grad(is);
  else
    throw;
  return is;
}