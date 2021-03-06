#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstddef>
using std::size_t;

#include "String_List.h"

// l is a pointer as shown in header file
// new string[1] returns a pointer of type std::string* to initial element.
String_List::String_List():l(new string[1]),max(1),size(0){}

// destructor
String_List::~String_List(){
  delete[] l;
}

void String_List::resize(){
  // copy array into new one with doubled size
  max *= 2;
  string* copy = new string[max];
  for(size_t i = 0; i < size; i++){
    copy[i] = l[i]; 
  }
  // garbage collection
  delete[] l;
  l = copy;
}

void String_List::push_back(string str){
  if(size == max){
    resize();
  }
  l[size++] = str;
}
