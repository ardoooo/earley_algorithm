#include "../include/state.h"

state::state(char in, std::string out, int pos_in_rule, int pos_in_str): 
    in(in), out(out), pos_in_rule(pos_in_rule), pos_in_str(pos_in_str) {};

bool state::operator==(const state& other) const {
    return (in == other.in) && (out == other.out) && (pos_in_rule == other.pos_in_rule) && (pos_in_str == other.pos_in_str);

}