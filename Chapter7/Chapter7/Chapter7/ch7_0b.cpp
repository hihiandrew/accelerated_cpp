#include <iostream>
#include <vector>
#include <string>

#include "split.h"
#include "loaders.h"

using namespace std;

/*
Categories Rules
<noun> cat
<noun> dog
<noun> table
<noun> Andrew
<nound> Devi
<noun-phrase> <noun>
<noun-phrase> <adjective> <noun-phrase>
<adjective> large
<adjective> brown
<adjective> absurd
<adjective> gregarious
<adjective> quiet
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