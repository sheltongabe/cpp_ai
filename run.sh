#!/bin/bash

DIR=$(pwd)

# Move to the bin directory and run
if [ ! -d bin ]; then
    echo "Must compile before running."
    exit 1
fi

cd bin
./cpp_ai_node_test
cd $DIR
