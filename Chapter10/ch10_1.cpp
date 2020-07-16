#include <algorithm>
using std::sort;
using std::max;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::cout;
using std::cin;
using std::endl;
using std::streamsize;

#include <iomanip>
using std::setprecision;

#include "ch10_0.h"
#include "ch10_1.h"
#include "read.h"
#include "median.h"

/*
 * while getline(in,s)
 * student_info class
 * record.read()
 * member function to calc/save grade
 * students vector
 * sort by grade, then alphabetically
 * loop over and print grade
 * */

Student_info::Student_info():midterm(0),finalexam(0){}
Student_info::Student_info(istream& in){read(in);}

double grade(double midterm, double finalexam, double hw){
  return 0.2 * midterm + 0.4 * finalexam + 0.4 * hw;
}

double grade(double midterm, double finalexam, vector<double> hw){
  return grade(midterm, finalexam, median(hw));
}

void Student_info::calc_grades(double grade){
  g = letter_grade(grade);
}

istream& Student_info::read(istream& in){
  if(in){
    in >> n >> midterm >> finalexam;
    read_hw(in, homework);
  }
  calc_grades(::grade(midterm,finalexam,homework));
  return in;
}

bool rank_students(Student_info& a, Student_info& b){
  if (a.grade() == b.grade()){
    return a.name() < b.name();
  }else{
    return a.grade() > b.grade();
  }
}

void student_results(){
  cout << "Please input student names and grades: " << endl;
  string::size_type maxlen = 0;
  Student_info record;
  vector<Student_info> students;
  // collect and save student records
  while (record.read(cin)){
   maxlen = max(maxlen,record.name().size());
   students.push_back(record);
  }
  // sort by grade then name
  sort(students.begin(), students.end(), rank_students);

  // print student ranking
  vector<Student_info>::const_iterator iter = students.begin();
  streamsize prec = cout.precision();
  while(iter != students.end()){
    cout << iter->name();
    cout << string(maxlen + 1 - iter->name().size(),' ');
    if(iter->valid()){
      cout << setprecision(3) << iter->grade();
      cout << setprecision(prec) << endl;;
    }else{
      cout << "No homework submitted." << endl;
    }
    ++iter;
  }
}

int ch10_1(){
  student_results();
  return 0;
}

