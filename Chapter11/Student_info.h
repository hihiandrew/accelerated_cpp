#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <list>

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
    //utility functions
    static void reset_call_count();
    static std::ostream& print_call_count(std::ostream&);
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
std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& read_hw(std::istream&, std::list<double>&);
double grade(const double&, const double&, const double);
double grade(const double&, const double&, const std::vector<double>&);
double median(std::vector<double>);
bool compare(const Student_info&, const Student_info&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::list<Student_info> extract_fails(std::list<Student_info>&);
#endif
