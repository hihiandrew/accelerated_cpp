#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "split.h"
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Categories Rules
<noun> cat
<noun> dog
<noun> table
<noun-phrase> <noun>
<noun-phrase> <adjective> <noun-phrase>
<adjective> large
<adjective> brown
<adjective> absurd
<verb> jumps
<verb> sits
<location> on the stairs
<location> under the sky
<location> wherever it wants
<sentence> the <noun-phrase> <verb> <location>

1. load into map<string,RuleCollection> grammar
2. load each Rule into a vector<string,vector<string>> RuleCollection;
3. build sentence output, recursive sentence_aux, w/ bracketed check
4. nrand -> random output
*/

typedef vector<string> Rule;
typedef vector<Rule> RuleCollection;
typedef map<string, RuleCollection> Grammar;

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

int nrand(int size) {
	if (size <= 0 || size > RAND_MAX) {
		throw domain_error("size out of bounds");
	}

	int bucket_size = RAND_MAX / size;
	int idx;

	// to avoid seeded rand()
	static unsigned seed;
	seed += 256*size;
	srand(seed);

	do idx = rand() / bucket_size;
	while (idx >= size); //if idx is out of range / >size, recalculate

	return idx;
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

vector<string> load_sentence(const Grammar& g) {
	vector<string> sentence;
	load_aux(g, "<sentence>", sentence);
	return sentence;
}


int ch7_0b(int num) {
	cout << "Please input a grammar map:" << endl;
	Grammar grammar = load_grammar(cin);

	for (int i = 0; i < num; i++) {
		vector<string> sentence = load_sentence(grammar);
		for (vector<string>::const_iterator iter = sentence.begin();
			iter < sentence.end(); iter++) {
			string punctuation = (iter == sentence.end() - 1) ? "." : " ";
			cout << *iter;
			cout << punctuation;
		}
		cout << endl;
	}

	return 0;
}