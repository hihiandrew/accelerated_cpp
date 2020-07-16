#ifndef GUARD_median_h
#define GUARD_median_h

#include <cstddef>
#include <algorithm>
#include <vector>
#include <stdexcept>

// T: element type, P: pointer/iterator type of container
template <class T, class P>
T median(P begin, P end){
  // check input is valid
  if(begin == end)
    throw std::domain_error("empty vector supplied to median()");
  // copy data into a vector
  std::vector<T> vec(begin,end);
  // sort and find median
  std::sort(vec.begin(),vec.end());
  typename std::vector<T>::size_type mid = vec.size() / 2; 
  return vec.size() % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
};

#endif // !GUARD_median_h
