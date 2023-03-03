cmake_minimum_required(VERSION 3.5)

project(week7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall")
# set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")


add_executable(week7 src/main.cpp src/exersice1.h src/exersice1.cpp src/exersice2.h src/exersice2.cpp)
