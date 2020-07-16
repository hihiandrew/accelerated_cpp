#include <cstddef>

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <string>
using std::string;

string letter_grade(double grade){
  // initialize grades
  static const double numbers[] = {97,94,90,87,82,80,77,74,70,60,0};
  // initialize letters
  static const char* const letters[] = {"A+","A","A-","B+","B","B-","C+","C","C-","D","F"};
  // size of letters[]
  static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);
  // calc grade
  for (size_t i=0; i<ngrades; ++i){
    if(grade >= numbers[i]){
      return letters[i];    
    }
  }
  return "?\?\?";  
}

void test_letter_grade(){
  cout << "Input a grade: " << endl;
  double x;
  cin >> x;
  cout << "Final grade is: " << letter_grade(x) << endl;
}

void copy_file(string file1, string file2){
  ifstream infile(file1);
  ofstream outfile(file2);
  string s;
  while(getline(infile,s)){
    outfile << s << endl;
  }
}

int read_files(int argc, char** argv){
  int fail_count = 0;
  for (int i = 1; i < argc; i++){
    ifstream infile(argv[i]);
    if (infile){
      string s;
      while(getline(infile, s)){
        cout << s << endl;
      }
    }else{
      fail_count++;
      cerr << "Cannot read file: " << argv[i] << endl;
    }
  }
  return fail_count;
}

int ch10_0(){
  copy_file("orig.txt","dest.txt");
  test_letter_grade();  
  return 0;
}
