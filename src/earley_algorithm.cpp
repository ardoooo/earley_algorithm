#include "../include/earley_algorithm.h"

bool add_state(std::unordered_multimap<char, state>& states, const state& state) {
    for (auto x: states) {
        if (x.second == state) {
            return false;
        }
    }
    states.emplace(state.out[state.pos_in_rule], state);
    return true;
}

bool scan(std::vector<std::unordered_multimap<char, state>>& states, int number, char symbol) {
    bool added = false;
    for (auto x: states[number - 1]) {
        state st = x.second;
        if (st.pos_in_rule < st.out.size() && st.out[x.second.pos_in_rule] == symbol) {
            added |= add_state(states[number], state(st.in, st.out, st.pos_in_rule + 1, st.pos_in_str));
        }
    }
    return added;
}

bool predict(const grammar& grammar, std::vector<std::unordered_multimap<char, state>>& states, const int number) {
    bool added = false;
    auto begin_it = grammar.get_rules().equal_range('A').first;
    auto end_it = grammar.get_rules().equal_range('Z').second;
    for (auto rule = begin_it; rule != end_it; ++rule) {
        auto range_in_states = states[number].equal_range(rule->first);
        for (auto st = range_in_states.first; st != range_in_states.second; ++st) {
            added |= add_state(states[number], state(rule->first, rule->second, 0, number));
        }
    }
    return added;
}

bool complete(std::vector<std::unordered_multimap<char, state>>& states, const int number) {
    bool added = false;
    auto begin_it = states[number].equal_range('$').first;
    auto end_it = states[number].equal_range('$').second;
    for (auto it = begin_it; it != end_it; ++it) {
        auto range_in_states = states[it->second.pos_in_str].equal_range(it->second.in);
        for (auto st = range_in_states.first; st != range_in_states.second; ++st) {
            added |= add_state(states[number], state(st->second.in, st->second.out, st->second.pos_in_rule + 1, st->second.pos_in_str));
        }
    }
    return added;
}

bool early_algorithm(const grammar& grammar, const std::string& str) {
    std::vector<std::unordered_multimap<char, state>> states(str.size() + 1);
    states[0].emplace('S', state('#', "S$", 0, 0)); // добавляем в states[0] (# -> S, 0)
    for (int i = 0; i <= str.size(); ++i) {
        if (i != 0) {
            scan(states, i, str[i - 1]);
        }
        bool changed = true;
        while(changed) {
            changed = predict(grammar, states, i);
            changed |= complete(states, i);
        }
    }

    for (auto st: states[str.size()]) {
        state end_st = state('#', "S$", 1, 0);
        if (st.second == end_st) {
            return true;
        }
    }
    return false;
}