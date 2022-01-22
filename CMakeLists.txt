cmake_minimum_required(VERSION 3.19)
project(aoc)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        aoc
        main.cpp
        puzzles/2015/01/Y2015D01.cpp
        puzzles/2015/02/Y2015D02.cpp
)