cmake_minimum_required(VERSION 3.9)
project(LeetCode_debug)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(leetcode/editor/cn/include)
LINK_LIBRARIES(leetcode)

add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp)
add_executable(2-add-two-numbers leetcode/editor/cn/2-add-two-numbers.cpp)
add_executable(26-remove-duplicates-from-sorted-array leetcode/editor/cn/26-remove-duplicates-from-sorted-array.cpp)
add_executable(101-symmetric-tree leetcode/editor/cn/101-symmetric-tree.cpp)
add_executable(226-invert-binary-tree leetcode/editor/cn/226-invert-binary-tree.cpp)
