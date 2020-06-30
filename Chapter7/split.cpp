#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
bool is_space(char c)
{
  return isspace(c);
}
bool not_space(char c)
{
  return !is_space(c);
}

vector<string> split(const string &s)
{
  typedef string::const_iterator iter;
  vector<string> words;

  iter i = s.begin();
  while (i != s.end())
  {

    // ignore leading blanks
    i = find_if(i, s.end(), not_space);

    // skip to end of word
    iter j = i;
    j = find_if(j, s.end(), is_space);

    // if valid word, add to result
    if (j != i)
    {
      words.push_back(string(i, j));
    }
  }
  return words;
}
