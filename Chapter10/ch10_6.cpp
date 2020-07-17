#include <string>
using std::string;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "String_List.h"
#include "split.h"

int ch10_6(){
  cout << "Please enter a stream of words" << endl;
  string x;
  while(getline(cin,x)){
    String_List stringlist = split(x);
    String_List::iterator iter = stringlist.begin();
    while(iter != stringlist.end()){
      cout << *iter++ << endl;
    }
  }
  return 0;
}
