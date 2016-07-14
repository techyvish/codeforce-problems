cmake_minimum_required(VERSION 3.1)
project(CompProgramming)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=stdlibc++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#set(SOURCE_FILES uva245.cpp)
set(SOURCE_FILES uva245.cpp dfs_traversal.cpp bfs_traversal.cpp dfs_floodfill.cpp topological_sort.cpp bipartite_graph.cpp uva507.cpp ABA12C.cpp HackerRank/FIBOMOD.cpp HackerRank/CANDIES.cpp HackerRank/MAXSUBARRAY.cpp UVA10684.cpp SPOJ/MREPLBRC.cpp)
add_executable(CompProgramming ${SOURCE_FILES})