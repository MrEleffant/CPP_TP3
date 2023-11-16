cmake_minimum_required(VERSION 3.26)
project(CPP_TP3)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        CPP_TP3
        Dummy.cpp
        Helper.cpp
        Helper.hpp
        Signal.cpp
        Signal.hpp
        types.h
        Dummy.hpp
        doctest.h
        signal_main_test.cpp
        bruit.cpp
        bruit.hpp
)
