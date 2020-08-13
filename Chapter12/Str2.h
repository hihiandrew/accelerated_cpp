#ifndef GUARD_Str2_h
#define GUARD_Str2_h

#include <algorithm>  //copy
#include <cstring>    //strlen
#include <iostream>   //istream,ostream
#include <iterator>   //back_inserter
#include <memory>

#include "Vec.h"

class Str2 {
 public:
  // required for write access to data
  friend std::istream& operator>>(std::istream&, Str2&);

  typedef size_t size_type;
  typedef char* iterator;
  typedef const char* const_iterator;
  typedef char value_type;

  // default constructor, empty Str
  Str2() { create(0, '\0'); }
  // Str containing copies of c
  Str2(size_type n, const char c) { create(n, c); }
  // Str from null-terminated array of char
  Str2(const char* cp) { create(cp); }
  // Str from Str
  Str2(const Str2& s) { create(s.d, s.d + s.size()); }
  // Str from range denoted by iterators
  template <class In>
  Str2(In b, In e) {
    create(b, e);
  }
  // destructor
  ~Str2() { uncreate(); }
  // assignment
  Str2& operator=(const Str2&);
  // private access
  const char* data() const { return d; };
  // operators, size
  size_type size() const { return len - 1; }
  char& operator[](size_type i) { return d[i]; }
  const char& operator[](size_type i) const { return d[i]; }
  Str2& operator+=(const char* cp) {
    append(cp, strlen(cp));
    return *this;
  }
  Str2& operator+=(const Str2& s) {
    append(s);
    return *this;
  }
  // returning iterators
  iterator begin() { return d; }
  iterator end() { return d + size(); }
  const_iterator begin() const { return d; }
  const_iterator end() const { return d + size(); }

 private:
  char* d;
  size_type len;
  std::allocator<char> alloc;

  void create(size_type n, const char s) {
    len = n + 1;
    d = new char[s + 1];
    memset(d, s, n);
    d[len - 1] = '\0';
  };

  void create(const char* cp) { create(cp, cp + std::strlen(cp)); };
  template <class In>
  void create(In b, In e) {
    len = e - b + 1;
    d = new char[len];
    memcpy(d, b, len - 1);
    d[len - 1] = '\0';
  }

  void append(const Str2&);
  void append(const char*, const size_type);
  void append(char);

  void uncreate() {
    if (len != 0) {
      delete[] d;
    }
    len = 0;
  };
};

// non-member operators

void Str2::append(char c) { append(&c, 1); }
void Str2::append(const Str2& s) { append(s.data(), s.size()); }
void Str2::append(const char* s, const size_type size) {
  size_type new_size = len + size;
  iterator new_data = alloc.allocate(new_size);
  iterator iter_append = std::uninitialized_copy(d, d + len - 1, new_data);
  std::uninitialized_copy(s, s + size, iter_append);
  uncreate();
  d = new_data;
  len += size;
  d[len] = '\0';
}

Str2& Str2::operator=(const Str2& rhs) {
  if (&rhs != this) {
    uncreate();
    create(rhs.data(), rhs.data() + rhs.size());
  }
  return *this;
}

// input/output: implicit binding of lhs operands
std::istream& operator>>(std::istream& is, Str2& s) {
  s.uncreate();
  s.create(0, '\0');
  char c;
  while (is.get(c) && isspace(c))
    ;
  if (is) {
    do
      s.append(c);
    while (is.get(c) && !isspace(c));
    if (is) {
      is.unget();
    }
  }
  return is;
}
std::ostream& operator<<(std::ostream& os, Str2& s) {
  copy(s.begin(), s.end(), std::ostream_iterator<char>(os));
  return os;
}
// + operator: does not change the state of lhs operand
Str2 operator+(const Str2& a, const Str2& b) {
  Str2 result = a;
  result += b;
  return result;
}

#endif
