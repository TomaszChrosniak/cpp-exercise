find_package(GTest REQUIRED)
find_package(Threads)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

include_directories(${GTEST_INCLUDE_DIRS})

message(STATUS "${GTEST_MAIN_LIBRARIES} ${CMAKE_CURRENT_BINARY_DIR}")

#include_directories("${CMAKE_SOURCE_DIR}/headers")
#add_library(CalculatorLib ${CALC_H} ${CALC_S})

file(GLOB CALC_TEST_H
	"${CMAKE_CURRENT_SOURCE_DIR}/*.h"
)

file(GLOB CALC_TEST_S
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(basic_test ${CALC_TEST_S} ${CALC_TEST_H})

target_link_libraries(basic_test
	Calculator
	${GTEST_BOTH_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT})
GTEST_ADD_TESTS(basic_test "" basic_test.cpp)
