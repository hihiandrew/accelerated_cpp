#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector <string> GetInput() {
	string word;
	vector<string> words;

	cout << "Please enter a string words, "
		"followed by an end-of-file input:" << endl;

	while (cin >> word) {
		words.push_back(word);
	}

	return words;
}

int LongShortString(vector<string> words) {
	typedef vector<string>::size_type words_sz;
	words_sz size = words.size();

	if (size == 0) {
		cout << "You must enter at least one word. "
			"Please try again." << endl;
		return 1;
	}

	string::size_type min_length = numeric_limits<int>::max();
	string::size_type max_length = 0;
	cout << "Numeric Limit max: " << min_length << endl;

	for (int i = 0; i < size; ++i) {
		string::size_type word_len = words[i].size();
		if (word_len < min_length) {
			min_length = word_len;
		}
		if (word_len > max_length) {
			max_length = word_len;
		}
	}

	cout << "The maximum string length is: " << max_length << ".\n"
		<< "The minimum string length is: " << min_length << "."
		<< endl;

	return 0;
}

int ch3_4() {
	/*
	Write a program to report the length of the
	longest and shortest string in its input.

	Idea:
	Initialize min and max values;
	Read input into a double x;
	Compare value against min and max values;
	Return min and max results via cout;
	*/

	return LongShortString(GetInput());
}