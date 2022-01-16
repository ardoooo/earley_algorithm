#pragma once
#include <vector>
#include <map>
#include <string>

class grammar {
private:
    std::multimap<char, std::string> rules;
public:
    grammar();
    grammar(const std::vector<std::string>& list_pules);

    std::pair<char, std::string> parse(const std::string& rule) const;
    void add_rule(const std::string& rules);

    const std::multimap<char, std::string>& get_rules() const;
};