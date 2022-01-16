#pragma once
#include <unordered_map>
#include "state.h"
#include "grammar.h"

// добавляет ситуацию в множество, если её там не было и возвращает true, иначе возвращает false
bool add_state(std::unordered_multimap<char, state>& states, const state& state);

// возвращает true, если были добавлены новые ситуации, иначе false
bool scan(std::vector<std::unordered_multimap<char, state>>& states, int number, char symbol);

// возвращает true, если были добавлены новые ситуации, иначе false
bool predict(const grammar& grammar, std::vector<std::unordered_multimap<char, state>>& states, const int number);

// возвращает true, если были добавлены новые ситуации, иначе false
bool complete(std::vector<std::unordered_multimap<char, state>>& states, const int number);

// возвращает true, если слово str принадлежит grammar, иначе false
bool early_algorithm(const grammar& grammar, const std::string& str);
