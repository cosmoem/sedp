#!/bin/bash

~/Qt5.12.10/5.12.10/clang_64/bin/qmake particles.pro CONFIG+=sdk_no_version_check
make
./particles.app/Contents/MacOS/particles