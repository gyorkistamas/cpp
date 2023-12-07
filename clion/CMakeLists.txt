cmake_minimum_required(VERSION 3.26)
project(clion)

set(CMAKE_CXX_STANDARD 17)

add_executable(clion main.cpp
        date.cpp
        worker.hpp
        worker.cpp)
