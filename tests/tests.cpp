#include "gtest/gtest.h"
#include "earley_algorithm.h"

TEST(SampleTestCase, Test_1) {
    std::vector<std::string> rules;
    rules.push_back("S->S+S");
    rules.push_back("S->S*S");
    rules.push_back("S->(S)");
    rules.push_back("S->a");
    rules.push_back("S->b");
    rules.push_back("S->c");
    grammar grammar(rules);
    bool ans = early_algorithm(grammar, "(a+b)*c");
    EXPECT_EQ(ans, true);
}

TEST(SampleTestCase, Test_2) {
    std::vector<std::string> rules;
    rules.push_back("S->aSbS");
    rules.push_back("S->");
    grammar grammar(rules);
    bool ans = early_algorithm(grammar, "ababab");
    EXPECT_EQ(ans, true);
}

TEST(SampleTestCase, Test_3) {
    std::vector<std::string> rules;
    rules.push_back("S->aSbS");
    rules.push_back("S->");
    grammar grammar(rules);
    bool ans = early_algorithm(grammar, "a");
    EXPECT_EQ(ans, false);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}