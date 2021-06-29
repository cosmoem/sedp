cmake_minimum_required(VERSION 3.6)
project(sedp_exercise5)

set(CMAKE_CXX_STANDARD 20)


add_executable(signal
    signal/signal.h
    signal/signal.cpp
    signal/main.cpp
)


add_executable(variant
    variant/variant.h
    variant/main.cpp
    variant/variant.cpp
)


add_executable(collect
    collect/collect.h
    collect/main.cpp
)


add_executable(template-refactoring
    template-refactoring/ISBN.h
    template-refactoring/main.cpp
)
