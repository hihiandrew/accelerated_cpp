#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<string> split(const string& s) {
	vector<string> result;
	string::size_type i = 0;
	string::size_type j = 0;
	while (i != s.size()) {
		// bump i past whitespace
		while (i != s.size() && isspace(s[i])) {
			i++;
		}
		// find end of current word
		j = i;
		while (j != s.size() && !isspace(s[j])) {
			j++;
		}
		// add word to result
		if (j != i) {
			result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}

int ch5_0() {
	// print all words into a column of words
	cout << "Please enter some words: " << endl;
	string s;
	while (getline(cin, s)) {
		vector<string> vec = split(s);
		for (vector<string>::size_type i = 0; i < vec.size(); i++) {
			cout << vec[i] << endl;
		}
	}
	return 0;
}