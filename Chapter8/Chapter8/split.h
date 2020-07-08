#ifndef GUARD_split_h
#define GUARD_split_h

#include <string>
#include <algorithm>

bool space(char);
bool not_space(char);
template <class Out>
void split(const std::string& s, Out os) {
	typedef std::string::const_iterator iter;

	iter i = s.begin();
	while (i != s.end()) {
		// find first char
		i = find_if(i, s.end(), not_space);

		// find end of string
		iter j = find_if(i, s.end(), space);

		// add to os
		*os++ = string(i, j);

		i = j;
	}
}

#endif // !GUARD_split_h
