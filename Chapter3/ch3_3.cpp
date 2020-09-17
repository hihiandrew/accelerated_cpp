#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "ch3_4.h"

using namespace std;

int DistinctWordCounter(vector<string> words) {
	typedef vector<string>::size_type words_sz;
	words_sz size = words.size();

	if (size == 0) {
		cout << "Please input at least one word." << endl;
		return 1;
	}

	sort(words.begin(), words.end());

	double count = 0;
	string current = words[0];

	for (vector<string>::size_type i = 0; i < size; ++i) {
		if (words[i] != current) {
			cout << "\"" << words[i-1] << "\" appeared "
				<< count << " times." << endl;
			count = 1;
			current = words[i];
		} else {
			count++;
		}
	}

	cout << "\"" << words[size-1] << "\" appeared "
		<< count << " times." << endl;

	return 0;
}

int ch3_3() {
	return DistinctWordCounter(GetInput());
}