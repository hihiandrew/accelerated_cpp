#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> center(vector<string>& vec) {
	sort(vec.begin(), vec.end());
	string::size_type max_len = 0;
	vector<string>::const_iterator iter = vec.begin();
	vector<string> result;
	while (iter != vec.end()) {
		max_len = max(max_len, iter++->size());
	}


	iter = vec.begin();
	while (iter != vec.end()) {
		string left = string((max_len - iter->size()) / 2, ' ');
		string right = string(max_len - iter->size() - left.size(), ' ');
		result.push_back(left + *iter++ + right);
	}

	return result;
}

int ch5_5() {
	vector<string> v = { "A really long string.", "Tasty chicken rice!",
		"Bismillah!d","TikTok is a wholesome application.","Andrew." };

	vector<string> centered = center(v);

	vector<string>::const_iterator iter = centered.begin();

	while (iter != centered.end()) {
		cout << *iter++ << endl;
	}

	return 0;
}