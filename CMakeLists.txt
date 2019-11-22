cmake_minimum_required(VERSION 3.14)
project(database)

set(CMAKE_CXX_STANDARD 14)

add_executable(database main.cpp src/DB/book.h src/algorithm/sort_times.cpp src/algorithm/sort_times.h src/DB/DB.h test.cpp)
add_executable(test test.cpp src/DB/book.h src/algorithm/sort_times.cpp src/algorithm/sort_times.h src/DB/DB.h test.cpp)