#include "Grader.h"
#include "read.h"

#include <algorithm>
using std::max;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::streamsize;

#include <iomanip>
using std::setprecision;

Grader::Grader(): grade(0){}
Grader::Grader(istream& in){read_grades(in);}

istream& Grader::read_grades(istream& in){
  double midterm, finalexam;
  vector<double> hw;
  in >> n >> midterm >> finalexam;
  read_hw(in, hw); 
  calc_grades(midterm,finalexam);
  return in;
}

void Grader::calc_grades(double midterm, double finalexam){
  grade = 2.0/3.0* midterm + 1.0/3.0*finalexam;
  p = grade > 60 ? "P" : "F";
}

void gen_report(){
  vector<Grader> grades;
  Grader grade;
  string::size_type maxlen=0;

  // read and save grades
  cout << "Please enter the students grades" << endl;
  while(grade.read_grades(cin)){
    maxlen = max(maxlen, grade.name().size());
    grades.push_back(grade); 
  }

  // sort alphabetically
  sort(grades.begin(),grades.end(),name_order);


  cout << "Grade Report:" << endl;
  for(vector<Grader>::size_type i = 0; i != grades.size(); ++i){
    //print name
    cout << grades[i].name() << string(maxlen+1 - grades[i].name().size(),' ');
    //print grade
    streamsize prec = cout.precision();
    cout << setprecision (3) << grades[i].pass() 
      << setprecision(prec) << endl;
  }
}

bool name_order(Grader& a, Grader& b){
  return a.name() < b.name();
}

