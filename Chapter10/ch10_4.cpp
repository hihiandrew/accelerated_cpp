#include <iostream>
using std::cout;
using std::endl;

#include "String_List.h"

void ch10_4(){
  String_List stringlist;
  
  stringlist.push_back("Andrew");
  stringlist.push_back("created");
  stringlist.push_back("this");
  stringlist.push_back("stringlist");
  stringlist.push_back("class!");

  String_List::iterator iter = stringlist.begin();
  while(iter != stringlist.end()){
    cout << *iter++ << endl;
  }

}
