#include "Str.h"

#include <iostream>
using std::istream;
using std::ostream;

// non-member operators operators
// input/output: implicit binding of lhs operands
istream& operator>>(istream& is, Str& s) {
  // obliterate existing values
  s.data.clear();
  // read and discard leading whitespace
  char c;
  while (is.get(c) && isspace(c)) {
    ;  // nothing to do, testing the condition
  }
  // if something to read, continue until next whitespace
  if (is) {
    do
      s.data.push_back(c);
    while (is.get(c) && !isspace(c));
    // if we encounter whitespace, put back on stream
    if (is) {
      is.unget();
    }
  }
  return is;
}
ostream& operator<<(ostream& os, Str& s) {
  for (Str::size_type i = 0; i < s.size(); ++i) {
    os << s[i];
  }
  return os;
}
// + operator: does not change the state of lhs operand
Str operator+(const Str& a, const Str& b) {
  Str result = a;
  result += b;
  return result;
}
