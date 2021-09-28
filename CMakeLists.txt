cmake_minimum_required(VERSION 3.20)
project(calculatrice_c C)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculatrice_c main.c calcullatriceFonction.c calcullatriceFonction.h myFunction.cpp myFunction.h)

