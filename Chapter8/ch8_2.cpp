#include <iostream>
#include <vector>

template <class InputIter1, class InputIter2>
bool equal(InputIter1 first1, InputIter1 last1, InputIter2 first2) {
	while (first1 != last1) {
		if (*first1++ != *first2++) {
			return false;
		}
	}
	return true;
}

template <class InputIter, class T>
InputIter find(InputIter first, InputIter last, const T& val) {
	while (first != last) {
		if (*first == val) return *first;
		++first;
	}
	return last;
}

template <class InputIter, class OutputIter>
OutputIter copy(InputIter first1, InputIter last1, OutputIter first2) {
	while (first1 != last1) {
		*first2++ = *first1++;
	}
	return OutputIter
}

template <class InputIter1, class InputIter2>
InputIter1 search(InputIter1 first1, InputIter1 last1,
	InputIter2 first2, InputIter2 last2) {
	if (first2 == last2) return first1;

	while (first1 != last1) {
		InputIter1 iter1 = first1;
		InputIter2 iter2 = first2;
		while (*iter1 == *iter2) {
			if (iter2 == last2) return first1;
			if (iter1 == last1) return last1;
			iter1++; iter2++;
		}
		++first1;
	}
	return last1;
}

template <class InputIter, class OutputIter, class UnaryOper>
OutputIter transform(InputIter first, InputIter last, OutputIter dest, UnaryOper op) {
	while (first != last) {
		*dest++ = op(*first++);
	}
	return dest
}

template <class InputIter, class T>
T accumulate(InputIter first, InputIter last, T val) {
	while (first != last) {
		val = val + *first++
	}
	return val;
}