#include "../include/earley_algorithm.h"
#include <iostream>

int main() {
    std::vector<std::string> rules;
    std::string word;
    std::string rule;
    int count = 0;
    std::cout << "Введите количество правил в грамматике:\n";
    std::cin >> count;
    std::cout << "Введите правила грамматики в формате A->aCdr\n";
    std::cout << "Можно использовать все ASCII символы\n";
    std::cout << "Для обозначения нетерминальных символ необходимо использовать заглавные латинские буквы";
    std::cout << "Стартовый символ всегда S\n";
    std::cout << "==================================\n";
    for (int i = 0; i < count; ++i) {
        std::cin >> rule;
        rules.push_back(rule);
    }
    std::cout << "==================================\n";
    std::cout << "Введите выражение для парсинга\n";
    std::cin >> word;

    grammar grammar(rules);
    if (early_algorithm(grammar, word)) {
        std::cout << "Слово принадлежит грамматике\n";
    } else {
        std::cout << "Слово не принадлежит грамматике\n";
    }
    return 0;
}
