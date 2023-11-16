cmake_minimum_required(VERSION 3.26)
project(CPP_TP3)

set(CMAKE_CXX_STANDARD 23)

add_executable(CPP_TP3
        Dummy.cpp
        Dummy.hpp
        Helper.cpp
        Helper.hpp
        Signal.cpp
        Signal.hpp
        signal_main_test.cpp
        types.h
        doctest.h
        Sinus.cpp
        Sinus.h
        bruit.cpp
        bruit.h)
