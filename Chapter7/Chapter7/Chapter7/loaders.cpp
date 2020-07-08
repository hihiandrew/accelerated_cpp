#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

#include "split.h"
#include "loaders.h"
#include "nrand.h"

using namespace std;

Grammar load_grammar(istream& in) {
	string line;
	Grammar g;

	while (getline(in, line)) {
		vector<string> entry = split(line);
		if (!entry.empty()) {
			g[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
		}
	}
	return g;
}

bool is_category(const string key) {
	return key.size() > 1 && key[0] == '<' && key[key.size() - 1] == '>';
}

vector<string> load_sentence(const Grammar& g) {
	vector<string> sentence;
	load_aux(g, "<sentence>", sentence);
	return sentence;
}

void load_aux(const Grammar& g, const string key, vector<string>& sentence) {

	if (!is_category(key)) {
		sentence.push_back(key);
	}
	else {
		// check key is in grammar map
		Grammar::const_iterator g_it = g.find(key);
		if (g_it == g.end()) {
			throw logic_error("empty Rule");
		}

		// randomly select one of the keys' rule collection rules
		const RuleCollection& c = g_it->second;
		const Rule& r = c[nrand(c.size())];

		for (Rule::const_iterator iter = r.begin(); iter != r.end(); iter++) {
			load_aux(g, *iter, sentence);
		}
	}
}