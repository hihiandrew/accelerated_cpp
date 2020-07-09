#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "split.h"
#include "xref.h"

using namespace std;

vector<string> unique_split(const string& s) {
	map<string, bool> seen;
	vector<string> unique;
	vector<string> dups = split(s);

	for (vector<string>::const_iterator iter = dups.begin(); iter < dups.end(); iter++) {
		map<string, bool>::const_iterator it = seen.find(*iter);
		if (it == seen.end()) {
			unique.push_back(*iter);
			seen[*iter] = true;
		}
	}
	return unique;
}

int ch8_5()
{
	cout << "Please input some words on a few lines: " << endl;
	map<string, vector<int>> result = xref(cin, unique_split);
	for (map<string, vector<int>>::const_iterator i = result.begin(); i != result.end(); i++)
	{
		cout << i->first << ": [";
		for (vector<int>::const_iterator j = i->second.begin(); j != i->second.end(); j++)
		{
			string punc = (j == i->second.end() - 1) ? "" : ",";
			cout << *j << punc;
		}
		cout << "]" << endl;
	}
	return 0;
}