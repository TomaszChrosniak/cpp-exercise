cmake_minimum_required (VERSION 2.8.11)
project (CPPExcercise)

add_executable(main main.cpp)

enable_testing()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	SET(GTEST_ROOT "C:/googletest" CACHE FILEPATH "The root directory of the gtest install prefix")
endif()

add_subdirectory(tests)
