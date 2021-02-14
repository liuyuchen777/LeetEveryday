cmake_minimum_required (VERSION 2.8)

project(leetcode_array)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Matrix matrix.h test.cpp)

target_link_libraries(Matrix ${GTEST_BOTH_LIBRARIES})
target_link_libraries(Matrix ${CMAKE_THREAD_LIBS_INIT})
add_test(Test Matrix)
enable_testing()