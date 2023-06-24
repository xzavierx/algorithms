cmake_minimum_required(VERSION 3.25)

project(sparse_table LANGUAGES CXX VERSION 0.0.1)

find_package(Catch2 3 REQUIRED)
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)


