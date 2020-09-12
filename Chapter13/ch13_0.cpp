#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::max;
using std::sort;

#include <iomanip>
using std::setprecision;
using std::streamsize;

#include <stdexcept>
using std::domain_error;

#include <fstream>
using std::ifstream;

#include "Core.h"
#include "Grad.h"
#include "Student_info.h"

// statically-bound solution, using object params
// inputs seperated by class
int undergrad_only() {
  vector<Core> students{};
  Core record{};
  string::size_type maxlen = 0;

  cout << "Testing statically bound class Undergrad only." << '\n'
       << "File: Students_10.txt" << endl;
  ifstream infile;
  infile.open("students_10.txt");

  while (record.read(infile)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  for (vector<Core>::size_type i = 0; i != students.size(); ++i) {
    cout << students[i].name()
         << string(maxlen + 1 - students[i].name().size(), ' ');
    try {
      double final_grade = students[i].grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec) << endl;
    } catch (domain_error& e) {
      cout << e.what() << endl;
    }
  }
  return 0;
}

int grad_only() {
  vector<Grad> students;
  Grad record;
  string::size_type maxlen = 0;

  cout << "Testing statically bound class Grad only." << '\n'
       << "File: Students_10.txt" << endl;
  ifstream infile;
  infile.open("students_10.txt");
  while (record.read(infile)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  for (vector<Grad>::size_type i = 0; i != students.size(); ++i) {
    cout << students[i].name()
         << string(maxlen + 1 - students[i].name().size(), ' ');
    try {
      double final_grade = students[i].grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec) << endl;
    } catch (domain_error& e) {
      cout << e.what() << endl;
    }
  }
  return 0;
}

int mixed_grades() {
  string filename = "students_10_mixed.txt";
  cout << "Testing mixed student input. \n File: " << filename << endl;
  ifstream infile;
  infile.open(filename);

  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while (record.read(infile)) {
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), Student_info::compare);

  for (vector<Student_info>::size_type i = 0; i < students.size(); ++i) {
    cout << students[i].name()
         << string(maxlen + 1 - students[i].name().size(), ' ');
    if(students[i].valid()){
      double final_grade = students[i].grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec) << endl;
    }else{
      cout << "No homework submitted." << endl;
    }
  }
  return 0;
}

int ch13_0() {
  grad_only();
  undergrad_only();
  mixed_grades();
  return 0;
}