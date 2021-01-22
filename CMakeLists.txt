cmake_minimum_required(VERSION 3.9)
project(LeetCode)
set(CMAKE_CXX_STANDARD 11)

#链接库
aux_source_directory(leetcode/editor/cn/include LEETCODE)
add_library(leetcode ${LEETCODE})
LINK_LIBRARIES(leetcode)


add_executable(1-two-sum leetcode/editor/cn/1-two-sum.cpp)
add_executable(100-same-tree leetcode/editor/cn/100-same-tree.cpp)