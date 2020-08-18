#include <iostream>

#include "Str2.h"
using std::cin;
using std::cout;
using std::endl;

int ch12_1() {
  cout << "testing ch12_1" << endl;
  Str2 S;
  S = "hello";
  cout << S << endl;
  Str2 W = " world Str2";
  S += W;
  cout << S << endl;

  Str2 s("hello");   // construct s
  Str2 t = "hello";  // initialize t
  s = "hello";      // assign a new value to s
  Str2 s1 = "test";
  Str2 s2 = "ing";
  Str2 s3 = s1 + s2;
  cout << s3 << endl;;            // use the addition operator to concatenate two strings
  cout << s << endl;
  cout << "Enter a Str2 string: ";
  cin >> s;           // use the input operator to read a string
  cout << s << endl;  // use the output operator to write a string
  cout << s[3] << endl;               // use the index operator to access a character

  Str2 name = "Andrew ver. Str2";
  Str2 greeting = "Hello, " + name + "!";

  Str2 temp1("Hello, ");      // Str::Str(const char*)
  Str2 temp2 = temp1 + name;  // operator*(const Str&, const Str&)
  Str2 temp3("!");            // Str::Str(const char*)
  greeting = temp2 + temp3;  // operator*(const Str&, const Str&)

  cout << greeting << endl;

  if(name){
    cout << "Boolean check: " << name << endl;
  }
  Str2 empty_name;
  if(empty_name){
    cout << "Boolean should not print: " << empty_name << endl;
  }

  Str2 input;
  cout << "testing for getline(), input few line:" << endl;
  while (getline(std::cin, input)){
    cout << input << endl;
  }
  return 0;
}