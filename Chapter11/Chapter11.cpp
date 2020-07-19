#include "Vec.h"
#include <iostream>

int main(){
  Vec<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(55);
  nums.push_back(5235);
  nums.push_back(3335);
  nums.push_back(928347);
  nums.push_back(2);
  nums.print_vec(std::cout);
  return 0;  
}
