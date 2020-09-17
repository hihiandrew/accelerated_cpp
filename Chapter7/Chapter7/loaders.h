#ifndef GUARD_loaders_h
#define GUARD_laoders_h

#include <vector>
#include <string>
#include <map>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> RuleCollection;
typedef std::map<std::string, RuleCollection> Grammar;

Grammar load_grammar(std::istream& in);
bool is_category(const std::string);
void load_aux(const Grammar&, const std::string, std::vector<std::string>&);
std::vector<std::string> load_sentence(const Grammar&);


#endif // !GUARD_loaders_h
