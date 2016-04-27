find_package(GTest REQUIRED)
find_package (Threads)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(basic_test basic_test.cpp)
target_link_libraries(basic_test
	${GTEST_BOTH_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT})
GTEST_ADD_TESTS(basic_test "" basic_test.cpp)
