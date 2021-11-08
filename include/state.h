#pragma once
#include <string>

struct state {
    char in; // левая часть правила
    std::string out; // правая часть правила
    int pos_in_rule; // позиция в правой части правила
    int pos_in_str; // позиция в строке, с которой начинается правило

    state(char in, std::string out, int pos_in_rule, int pos_in_str);

    bool operator==(const state& other) const;
};