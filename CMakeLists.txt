cmake_minimum_required(VERSION 3.11)

project(alogs VERSION 1.0.0)

Include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.1
)
FetchContent_MakeAvailable(Catch2)
#add_subdirectory(Catch2)
add_subdirectory(st)
