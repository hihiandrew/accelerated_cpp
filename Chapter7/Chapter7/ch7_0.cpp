#include <vector>
#include <map>
#include <iostream>
#include <string>
#include "split.h"

using namespace std;

/*
reads lines and saves unique words to map
map = word:[line number]
*/

map<string, vector<int>> xref(istream &in, vector<string> find_words(const string &) = split)
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
  }

  return result;
}

int ch7_0()
{
  cout << "Please input some words on a few lines: " << endl;
  map<string, vector<int>> result = xref(cin);
  for (map<string, vector<int>>::const_iterator i = result.begin(); i != result.end(); i++)
  {
    cout << i->first << endl;
    for (vector<int>::const_iterator j = i->second.begin(); j != i->second.end(); j++)
    {
      cout << *j << " ";
    }
    cout << endl;
  }
  return 0;
}
