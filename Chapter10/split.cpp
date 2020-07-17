#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "String_List.h"

using namespace std;
bool is_space(char c)
{
  return isspace(c);
}
bool not_space(char c)
{
  return !is_space(c);
}

String_List split(const string &s)
{
  typedef string::const_iterator iter;
  String_List stringlist;

  iter i = s.begin();
  while (i != s.end())
  {
    // ignore leading blanks
    i = find_if(i, s.end(), not_space);

    // skip to end of word
    iter j = find_if(i, s.end(), is_space);

    // if valid word, add to result
    if (i != s.end())
    {
      stringlist.push_back(string(i, j));
      i = j;
    }
  }
  return stringlist;
}
