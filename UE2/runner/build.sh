#!/bin/bash

c++ -std=c++14 -I . -o runner.cpp.o -c runner.cpp
c++ runner.cpp.o -o runner -rdynamic externallibrary.dylib -Wl,-rpath,.
./runner 1
echo "Verify that main returns zero: " $?
echo ""
./runner 1000000
echo "Verify that main returns zero: " $?
