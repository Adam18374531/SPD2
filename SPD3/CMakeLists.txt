cmake_minimum_required(VERSION 3.23)
project(SPD3)

set(CMAKE_CXX_STANDARD 14)

add_executable(SPD3 main.cpp Johnson.cpp Johnson.h NEH.cpp NEH.h wczytywanie.cpp wczytywanie.h problem.cpp problem.h brute_force.cpp brute_force.h)
