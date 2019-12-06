cmake_minimum_required(VERSION 3.14)
project(database)

set(CMAKE_CXX_STANDARD 14)

add_executable(database
        main.cpp
        src/DB/book.h
        src/algor/sort_times.h
        src/DB/DB.h
        src/DB/binary_tree.h
        src/indexes/search.h
        src/indexes/search.cpp
        src/cache/pool.h
        src/DB/temp.h)
