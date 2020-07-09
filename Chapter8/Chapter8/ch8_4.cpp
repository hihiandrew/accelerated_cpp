#include "ch8_4.h"
#include <vector>
#include <iostream>

int ch8_4() {

	std::vector<int> vec = { 1,2,3,4,5,6,7 };
	std::reverse(vec.begin(), vec.end());
	std::vector<int>::const_iterator iter = vec.begin();
	while (iter != vec.end()) {
		std::cout << *iter++ << " ";
	}
	std::cout << std::endl;

	return 0;
}