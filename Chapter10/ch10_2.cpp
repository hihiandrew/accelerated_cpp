#include "median.h"
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::end;

void test_median(){
  //arrays
  int arr_int[] = {6,5,4,3,2,1};
  double arr_dbl[] = {6.0,5.0,4.0,3.0,2.0,1.0};
  //vectors
  vector<int> vec_int(arr_int,arr_int+6);
  vector<double> vec_dbl(arr_dbl,arr_dbl+6);

  cout << "Median (arr<int>) is: " 
    << median<int,int*>(arr_int,end(arr_int)) << endl;
  cout << "Median (arr<dbl>) is: " 
    << median<double,double*>(arr_dbl,end(arr_dbl)) << endl;

  cout << "Median (vec<int>) is: " << 
    median<int,vector<int>::iterator>(vec_int.begin(),vec_int.end()) << endl;
  cout << "Median (vec<dbl>) is: " << 
    median<double,vector<double>::iterator>(vec_dbl.begin(),vec_dbl.end()) << endl;
}

int ch10_2(){
  test_median();
  return 0;
}
