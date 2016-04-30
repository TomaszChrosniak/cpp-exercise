find_package(GTest REQUIRED)
find_package(Threads)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

include_directories(${GTEST_INCLUDE_DIRS})

message(STATUS "${GTEST_MAIN_LIBRARIES} ${CMAKE_CURRENT_BINARY_DIR}")

set(TEST_SOURCES basic_test.cpp calculatorTest.h calculatorTest.cpp)

add_executable(basic_test ${TEST_SOURCES} ../Calculator.h ../Calculator.cpp)

target_link_libraries(basic_test
	${GTEST_BOTH_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT})
GTEST_ADD_TESTS(basic_test "" basic_test.cpp)
