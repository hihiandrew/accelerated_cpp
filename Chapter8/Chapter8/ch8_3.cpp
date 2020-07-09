#include "ch8_3.h"
#include "median.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using std::chrono::steady_clock;

#include <iterator>

int ch8_3()
{
    vector<int> vec1 = { 8, 71, 175, 5, 49 , 666 };

    // sorting the vector so the sorting step in the median functions won't affect performance
    std::sort(vec1.begin(), vec1.end());
    typedef steady_clock::time_point tp;

    tp begin1 = steady_clock::now();
    for (int i = 0; i < 1000; i++) {
        median(vec1);
    }
    tp end1 = steady_clock::now();
    cout << "Microseconds to run median 1000 times using pass by value = " << std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1).count() << endl;

    tp begin2 = steady_clock::now();
    for (int i = 0; i < 1000; i++) {
        median_iter<vector<int>::iterator, int>(vec1.begin(), vec1.end());
    }
    tp end2 = steady_clock::now();
    cout << "Microseconds to run median 1000 times using iterators = " << std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2).count() << endl;

    return 0;
}