cmake_minimum_required (VERSION 2.8.11)
project (CPPExcercise)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB CALC_H
	"${CMAKE_SOURCE_DIR}/headers/*.h"
)

file(GLOB CALC_S
	"${CMAKE_SOURCE_DIR}/sources/*.cpp"
)

add_library(Calculator ${CALC_H} ${CALC_S})

include_directories("${CMAKE_SOURCE_DIR}/headers")
add_executable(main main.cpp)
target_link_libraries(main Calculator)

enable_testing()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	SET(GTEST_ROOT "C:/googletest" CACHE FILEPATH "The root directory of the gtest install prefix")
endif()

add_subdirectory(tests)
