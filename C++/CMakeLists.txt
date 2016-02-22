cmake_minimum_required(VERSION 3.3)
project(leetcode_C___)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp 1_Two_Sum.cpp all_header.h 2_Add_Two_Numbers.cpp 3_Longest_Substring_Without_Repeating_Characters.cpp 4_Median_of_Two_Sorted_Arrays.cpp 5_Longest_Palindromic_Substring.cpp 6_ZigZag_Conversion.cpp 7_Reverse_Integer.cpp "8_String_to_Integer_(atoi).cpp" 9_Palindrome_Number.cpp 10_Regular_Expression_Matching.cpp 11_Container_With_Most_Water.cpp 12_Integer_to_Roman.cpp 13_Roman_to_Integer.cpp 14_Longest_Common_Prefix.cpp)
add_executable(leetcode_C___ ${SOURCE_FILES})