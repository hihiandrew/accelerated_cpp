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
  // Str from range denoted by iterators
  template <class In>
  Str2(In b, In e) {
    create(In b, In e);
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
    append(cp, std::strlen(cp));
    return *this;
  }
  Str2& operator+=(const Str2& s) {
    append(s);
    return *this;
  }

  // support functions for +=

 private:
  // memory management
  std::allocator<char> alloc;

  void Str2::create(size_type n, const char s) {
    len = n + 1;
    d = alloc.allocate(len);
    std::uninitialized_fill(d, d + n, s);
    d[n] = '\0';
  }

  void create(const char* cp) { create(cp, cp + std::strlen(cp)); };
  template <class In>
  void create(In b, In e) {
    len = b - e + 1;
    data = alloc.allocate(len);
    std::uninitialized_copy(b, e, data);
    data[len] = '\0';
  };

  void append(const Str2&);
  void append(const char*, const size_type);

  void uncreate() {
    if (d) {
      iterator iter = d + len;
      while (iter != d) alloc.destroy(--iter);
      alloc.deallocate(d, len);
    }
    len = 0;
    d[0] = '\0';
  };

  char* d;
  size_type len;
};

// non-member operators operators

Str2& Str2::operator=(const Str2& rhs) {
  if (&rhs != this) {
    uncreate();
    create(rhs.data(), rhs.data() + rhs.size());
  }
  return *this;
}

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
void Str2::append(const Str2& s) { append(s.data(), s.size()); }
// input/output: implicit binding of lhs operands
// std::istream& operator>>(std::istream& is, Str2& s) {
//   // obliterate existing values
//   s.data.clear();
//   // read and discard leading whitespace
//   char c;
//   while (is.get(c) && isspace(c)) {
//     ;  // nothing to do, testing the condition
//   }
//   // if something to read, continue until next whitespace
//   if (is) {
//     do
//       s.data.push_back(c);
//     while (is.get(c) && !isspace(c));
//     // if we encounter whitespace, put back on stream
//     if (is) {
//       is.unget();
//     }
//   }
//   return is;
// }
std::ostream& operator<<(std::ostream& os, Str2& s) {
  for (Str2::size_type i = 0; i < s.size(); ++i) {
    os << s[i];
  }
  return os;
}
// + operator: does not change the state of lhs operand
Str2 operator+(const Str2& a, const Str2& b) {
  Str2 result = a;
  result += b;
  return result;
}

#endif
