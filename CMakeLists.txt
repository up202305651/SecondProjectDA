cmake_minimum_required(VERSION 3.10)
project(SecondProjectDA)

set(CMAKE_CXX_STANDARD 20)

# Find GLPK package
find_library(GLPK_LIBRARY NAMES glpk)
if(NOT GLPK_LIBRARY)
    message(FATAL_ERROR "GLPK library not found")
endif()

add_executable(SecondProjectDA main.cpp
        reader.cpp
        reader.h
        pallet.h
        bruteforce.cpp
        bruteforce.h
        greedy.cpp
        greedy.h
        dynamic_prog.cpp
        dynamic_prog.h
        ilp.h
        ilp.cpp
)

# Link with GLPK
target_link_libraries(SecondProjectDA ${GLPK_LIBRARY})