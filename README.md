# earley_algorithm
 ## Сборка
 - mkdir build && cd build
 - cmake -DBUILD_TESTS=ON .. или cmake .. первая, если хотите подключить тестирование
 - make
 - (optional) make coverage - генерирует файл с CodeCoverage index.html, который лежит в build/coverage


## Запуск
- ./bin/earley_algorithm запускает программу
- ./bin/Test запускает тестирование
