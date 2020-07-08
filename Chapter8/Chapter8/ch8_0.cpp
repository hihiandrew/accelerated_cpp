#include <string>
#include <vector>
#include <iostream>
#include "median.h"
#include "split.h"
using namespace std;

int ch8_0() {
	std::vector<int> vec = { 4,5,6,1,2,3 };
	int num = median(vec);
	std::cout  << num2 << endl;

	string s;
	while (getline(cin, s)) {
		split(s, ostream_iterator<string>(cout, "_"));
	}
}