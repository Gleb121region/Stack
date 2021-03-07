cmake_minimum_required(VERSION 3.17)
project(HomeTask)

set(CMAKE_CXX_STANDARD 14)

add_executable(HomeTask
        main.cpp
        Stack.h
        StackArray.h StackList.h
        StackOverflow.cpp StackOverflow.hpp StackUnderflow.cpp StackUnderflow.hpp WrongStackSize.cpp WrongStackSize.hpp)