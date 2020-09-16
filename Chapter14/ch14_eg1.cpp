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

#include "Handle.h"
#include "Core.h"
#include "Grad.h"
//#include "Student_info.h"

bool compare_Core_handles(const Handle<Core>& a, const Handle<Core>& b) {
  return a->name() < b->name();
}

int mixed_students_eg14() {
  string filename = "students_10_mixed.txt";
  cout << "Testing Handle Class. \n File: " << filename << endl;
  ifstream infile;
  infile.open(filename);

  vector<Handle<Core>> students;
  Handle<Core> record;
  string::size_type maxlen = 0;
  char ch;

  while (infile >> ch) {
    // need to add student type condition here
    if (ch == 'U')
      record = new Core;
    else
      record = new Grad;
    record->read(infile);
    maxlen = max(maxlen, record->name().size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare_Core_handles);

  for (vector<Handle<Core>>::size_type i = 0; i < students.size(); ++i) {
    cout << students[i]->name()
         << string(maxlen + 1 - students[i]->name().size(), ' ');
    if (students[i]->complete()) {
      double final_grade = students[i]->grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec) << endl;
    } else {
      cout << "Did not meet requirements." << endl;
    }
  }
  return 0;
}

int ch14_eg1() {
  mixed_students_eg14();
  return 0;
}