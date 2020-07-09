#ifndef GUARD_8_3_H
#define GUARD_8_3_H

#include <iterator>
#include <stdexcept>
#include <algorithm>

int ch8_3();

template<class RandIter, class T>
T median_iter(RandIter first, RandIter last){
    T count = std::distance(first, last);

    if (count == 0)
        throw std::domain_error("median of an empty container");

    std::sort(first, last);

    T mid = count / 2;

    std::advance(first, mid - 1);

    return count % 2 == 0 ? (*first++ + *first) / 2 : *++first;
}

#endif // !GUARD_8_3_H