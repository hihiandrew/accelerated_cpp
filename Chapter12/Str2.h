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
  friend std::istream& getline(std::istream&, Str2&);

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
  const char* c_str() const { return d; };
  // handles boolean
  operator void*() const{
    return size()>0 ? d : 0;
  };
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
  size_type copy(char*, size_type) const;
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
    d = alloc.allocate(len);
    std::uninitialized_fill(d, d + n, s);
    // d = new char[s + 1];
    // memset(d, s, n);
    d[len - 1] = '\0';
  };

  void create(const char* cp) { create(cp, cp + std::strlen(cp)); };
  template <class In>
  void create(In b, In e) {
    len = e - b + 1;
    d = alloc.allocate(len);
    std::uninitialized_copy(b, e, d);
    // d = new char[len];
    // memcpy(d, b, len - 1);
    d[len - 1] = '\0';
  }

  void append(const Str2&);
  void append(const char*, const size_type);
  void append(char);

  void uncreate() {
    if (len != 0) {
      iterator iter = d + len;
      while (iter != d) alloc.destroy(--iter);
      alloc.deallocate(d, len);
      // delete[] d;
    }
    len = 0;
  };
};

// non-member operators

void Str2::append(char c) { append(&c, 1); }
void Str2::append(const Str2& s) { append(s.data(), s.size()); }
void Str2::append(const char* s, const size_type size) {
  size_type new_len = len + size;
  iterator new_data = alloc.allocate(new_len);
  iterator iter_append = std::uninitialized_copy(d, d + len - 1, new_data);
  std::uninitialized_copy(s, s + size, iter_append);
  uncreate();
  d = new_data;
  len = new_len;
  d[len] = '\0';
}

Str2::size_type Str2::copy(char* dest, Str2::size_type count)const{
  Str2::size_type i;
  for(i=0; i<count && i<size(); i++){
    dest[i] = d[i];
  }
  return i;
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

std::istream& getline(std::istream& is, Str2& s){
  s.uncreate();
  s.create(0,'\0');
  char c;
  if(is){
    while ( is.get(c) && c != '\n'){
      s.append(c);
    }
  }
  return is;
}

// + operator: does not change the state of lhs operand
Str2 operator+(const Str2& a, const Str2& b) {
  Str2 result = a;
  result += b;
  return result;
}
Str2 operator+(const char* a, const Str2& b){
  Str2 result = b;
  result += a;
  return result;
}
Str2 operator+(const Str2& a, const char* b){
  Str2 result = a;
  result += b;
  return result;
}

inline bool operator==(const Str2& lhs, const Str2& rhs){
  return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

inline bool operator!=(const Str2& lhs, const Str2& rhs){
  return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

inline bool operator<(const Str2& lhs, const Str2& rhs){
  return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

inline bool operator<=(const Str2& lhs, const Str2& rhs){
  return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

inline bool operator>(const Str2& lhs, const Str2& rhs){
  return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}

inline bool operator>=(const Str2& lhs, const Str2& rhs){
  return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
#endif
