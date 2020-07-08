#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
#include "split.h"

using namespace std;

/*
reads lines and saves unique words to map
map = word:[line numbers]
*/
map<string, vector<int>> xref(istream& in, vector<string> find_words(const string&) = split)
{
    map<string, vector<int>> result;
    string line;
    int line_number = 0;

    while (getline(in, line))
    {
        ++line_number;
        vector<string> words = find_words(line);

        for (vector<string>::const_iterator it = words.begin();
            it < words.end(); ++it)
        {
            result[*it].push_back(line_number);
        }

        // unique values only ch7_3()
        map<string, vector<int>>::const_iterator last = unique(result.begin(), result.end());
        result.erase(last, result.end());
    }

    return result;
}