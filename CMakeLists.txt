cmake_minimum_required (VERSION 2.8.11)
project (CPPExcercise)

add_executable(main main.cpp)

enable_testing()
add_subdirectory(tests)