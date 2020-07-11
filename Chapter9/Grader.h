#ifndef GUARD_Grader_h
#define GUARD_Grader_h

#include <iostream>
#include "Student_info.h"
class Grader{
  public:
    //constructors
    Grader();
    Grader(std::istream&);
    //member functions
    std::istream& read_grades(std::istream&);
    std::string pass() const {return p;}
    std::string name() const {return n;} 
    void calc_grades(double, double);

  private:
    std::string n;
    std::string p;
    double grade;
};
void gen_report();
bool name_order(Grader&, Grader&);
#endif
