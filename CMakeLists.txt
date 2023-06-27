cmake_minimum_required(VERSION 3.11)

project(alogs VERSION 1.0.0)
set(CMAKE_BUILD_TYPE "Debug")

Include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.1
)
FetchContent_MakeAvailable(Catch2)
#add_subdirectory(Catch2)
add_subdirectory(st)
add_subdirectory(seg_tree)
