#ifndef GUARD_ch10_1_h
#define GUARD_ch10_1_h

#include <string>
#include <vector>

class Student_info{
  public:
    // constructors:
    Student_info();
    Student_info(std::istream&);
    // public member function:
    void calc_grades(double);
    bool valid() const {return !homework.empty();}
    std::string grade() const {return g;}   
    std::string name() const {return n;}
    std::istream& read(std::istream&); 
  private:
    double midterm, finalexam;
    std::string n,g;
    std::vector<double> homework; 
};

bool rank_students(Student_info&, Student_info&);
double grade(double&, double&, double&);
double grade(double&, double&, std::vector<double>&);
int ch10_1();
#endif
