cmake_minimum_required(VERSION 3.30)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1
        main.cpp
        reader.cpp
        bruteforce.cpp
        bruteforce.h
        greedy.cpp
        greedy.h
        dynamic_prog.cpp
        dynamic_prog.h
        read_write.cpp
        read_write.h
        ilp.cpp
        ilp.h
)