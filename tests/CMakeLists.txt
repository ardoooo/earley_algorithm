cmake_minimum_required(VERSION 3.1)

add_executable(Test tests.cpp ../src/state.cpp ../src/grammar.cpp ../src/earley_algorithm.cpp)
#target_link_libraries(Test Library)

target_link_libraries(Test gtest_main gtest gmock Threads::Threads)