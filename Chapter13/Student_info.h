#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <iostream>
#include <vector>
#include "grade.h"
#include "read.h"

class Student_info{
  public:
    // constructors
    Student_info(); // construct an empty Student_info object
    Student_info(std::istream&); // constructs one by reading from a stream
    // public member function 
    std::string name() const {return n;}
    bool valid() const {return !homework.empty();}
    double get_grade() const {return finalgrade;}
    void calc_grade();
    std::istream& read(std::istream&);
  private:
    // private data members
    std::string n;
    std::vector<double> homework;
    double midterm, finalexam, finalgrade;
};

bool compare(const Student_info&, const Student_info&);

#endif
