#include <algorithm>
using std::sort;
using std::max;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::streamsize;
using std::endl;

#include <iomanip>
using std::setprecision;

#include <stdexcept>
using std::domain_error;

#include "Student_info.h"
#include "ch9_0.h"

int ch9_1(){

  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen=0;
  
  // prompt users to input grades
  cout << "Please enter the students grades: " << endl;

  // read and store data
  while (record.read(cin)){
    maxlen = max(maxlen, record.name().size());
    students.push_back(record);
  }

  // alphabetize the students
  sort(students.begin(),students.end(),compare);

  // write the names and grades
  for (vector<Student_info>::size_type i=0; i!=students.size(); ++i){
    cout << students[i].name()
      << string(maxlen+1 - students[i].name().size(),' ');
    if(students[i].valid()){
      streamsize prec = cout.precision();
      cout << setprecision(3) << students[i].get_grade() 
       << setprecision(prec) << endl;
    }else{
      cout << "No homework submitted." << endl;
    }
  }
  return 0;
}
