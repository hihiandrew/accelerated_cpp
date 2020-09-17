#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "xref.h"

using namespace std;

int ch7_0()
{
  cout << "Please input some words on a few lines: " << endl;
  map<string, vector<int>> result = xref(cin);
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
