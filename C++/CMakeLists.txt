cmake_minimum_required(VERSION 3.3)
project(leetcode_C___)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp 1_Two_Sum.cpp all_header.h 2_Add_Two_Numbers.cpp
        3_Longest_Substring_Without_Repeating_Characters.cpp 4_Median_of_Two_Sorted_Arrays.cpp
        5_Longest_Palindromic_Substring.cpp 6_ZigZag_Conversion.cpp 7_Reverse_Integer.cpp
        "8_String_to_Integer_(atoi).cpp" 9_Palindrome_Number.cpp 10_Regular_Expression_Matching.cpp
        11_Container_With_Most_Water.cpp 12_Integer_to_Roman.cpp 13_Roman_to_Integer.cpp 14_Longest_Common_Prefix.cpp
        15_3Sum.cpp 16_3Sum_Closest.cpp 17_Letter_Combinations_of_a_Phone_Number.cpp 18_4Sum.cpp
        19_Remove_Nth_Node_From_End_of_List.cpp 20_Valid_Parentheses.cpp 21_Merge_Two_Sorted_Lists.cpp
        22_Generate_Parentheses.cpp 23_Merge_k_Sorted_Lists.cpp 24_Swap_Nodes_in_Pairs.cpp
        25_Reverse_Nodes_in_k-Group.cpp 26_Remove_Duplicates_from_Sorted_Array.cpp 27_Remove_Element.cpp
        "28_Implement_strStr().cpp" 29_Divide_Two_Integers.cpp 30_Substring_with_Concatenation_of_All_Words.cpp
        31_Next_Permutation.cpp 32_Longest_Valid_Parentheses.cpp 33_Search_in_Rotated_Sorted_Array.cpp
        34_Search_for_a_Range.cpp 35_Search_Insert_Position.cpp 36_Valid_Sudoku.cpp 37_Sudoku_Solver.cpp
        38_Count_and_Say.cpp)
add_executable(leetcode_C___ ${SOURCE_FILES})