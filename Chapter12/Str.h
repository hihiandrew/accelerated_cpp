#ifndef GUARD_Str_h
#define GUARD_Str_h

#include <algorithm>  //copy
#include <cstring>    //strlen
#include <iostream>   //istream,ostream
#include <iterator>   //back_inserter

#include "Vec.h"

class Str {
  // required for write access to data
  friend std::istream& operator>>(std::istream&, Str&);

 public:

  typedef Vec<char>::size_type size_type;
  typedef Vec<char>::iterator iterator;
  typedef Vec<char>::const_iterator const_iterator;

  // default constructor, empty Str
  Str() {}

  // Str containing copies of c
  Str(size_type n, char c) : data(n, c) {}
  
  // Str from null-terminated array of char
  Str(const char* cp) {
    std::copy(cp, cp + std::strlen(cp), std::back_inserter(data));
  }

  // Str from range denoted by iterators
  template <class In>
  Str(In b, In e) {
    std::copy(b, e, std::back_inserter(data));
  }

  // operators, size
  size_type size() const { return data.size(); }
  char& operator[](size_type i) { return data[i]; }
  const char& operator[](size_type i) const { return data[i]; }

  Str& operator+=(const Str& s) {
    std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
    return *this;
  }

 private:

  Vec<char> data;

};

std::istream& operator>>(std::istream&, Str&);
std::ostream& operator<<(std::ostream&, Str&);
Str operator+(const Str&, const Str&);

#endif
