#include "../include/grammar.h"

grammar::grammar() = default;

grammar::grammar(const std::vector<std::string>& list_rules) {
    for (auto rule: list_rules) {
        add_rule(rule);
    }
}

std::pair<char, std::string> grammar::parse(const std::string& rule) const {
    return std::make_pair(rule[0], rule.substr(3) + "$");
}

void grammar::add_rule(const std::string& rule) {
    rules.insert(parse(rule));
}

const std::multimap<char, std::string>& grammar::get_rules() const {
    return rules;
}
