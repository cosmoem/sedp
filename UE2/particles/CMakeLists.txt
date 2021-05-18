cmake_minimum_required(VERSION 3.19)
project(particles)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(Qt5_DIR "/Users/frieda/Qt5.12.10/5.12.10/clang_64/lib/cmake/Qt5")

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(particles
        engine.cpp
        engine.h
        main.cpp
        particle.cpp
        particle.h
        widget.cpp
        widget.h)

target_link_libraries(particles Qt5::Widgets)