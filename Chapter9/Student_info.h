#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <iostream>
#include <vector>
#include "grade.h"

class Student_info{
  public:
    // constructors
    Student_info(); // construct an empty Student_info object
    Student_info(std::istream&); // construcs one by reading from a stream
    // public member function 
    std::string name() const {return n;}
    bool valid() const {return !homework.empty()}
    std::istream& read(std::istream&);
    double grade() const;
  private:
    // private data members
    std:: string n;
    double midterm final;
    std::vector<double> homework;
};
bool compare(const Student_info&, const Student_info&);

#endif
