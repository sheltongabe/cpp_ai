#!/bin/sh

DIR=$(pwd)

# Move to the build directory and compile it
if [ ! -d build ]; then
    mkdir build
fi

cd build/

cmake .. && make

# Move back to the original directory
cd $DIR
