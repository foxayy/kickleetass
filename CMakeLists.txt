cmake_minimum_required(VERSION 3.15)
project(kickleetass)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        MinimumPathSum Array/64/solution.cpp
)
add_executable(
        UniquePaths Array/62/solution.cpp
)
add_executable(
        CombinationSumII Array/40/solution.cpp
)

add_executable(
        MergeIntervals Array/56/solution.cpp
)

add_executable(
        UniquePathsII Array/63/solution.cpp
)

add_executable(
        JumpGame Array/55/solution.cpp
)