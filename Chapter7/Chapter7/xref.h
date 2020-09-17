#ifndef GUARD_xref_h
#define GUARD_xref_h

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include "split.h"

std::map<std::string, std::vector<int>> xref(std::istream& in,
	std::vector<std::string> find_words(const std::string&) = split);

#endif // !GUARD_xref_h
