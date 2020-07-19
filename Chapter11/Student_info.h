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
    // copy constructor
    Student_info(const Student_info&);
    // assignment operator
    Student_info& operator=(const Student_info&);
    // destructor operator
    ~Student_info();
    // helper counters
    static void reset_counters();
    static void print_counters();
    // public member function 
    std::string name() const {return n;}
    bool valid() const {return !homework.empty();}
    double get_grade() const {return finalgrade;}
    void calc_grade();
    std::istream& read(std::istream&);
  private:
    // counters
    static int default_constructor_calls;
    static int stream_constructor_calls;
    static int copy_constructor_calls;
    static int assignment_operator_calls;
    static int destructor_calls;

    // private data members
    std::string n;
    std::vector<double> homework;
    double midterm, finalexam, finalgrade;
};

bool compare(const Student_info&, const Student_info&);

#endif
