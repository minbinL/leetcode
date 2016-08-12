cmake_minimum_required(VERSION 3.3)
project(leetcode_C___)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(. SOURCE_FILES)
add_executable(leetcode_C___ ${SOURCE_FILES})
