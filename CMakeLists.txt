cmake_minimum_required(VERSION 3.17)
project(mvn_compare_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(mvncmp main.cpp MvnVersion.cpp MvnVersion.h utils.h)
