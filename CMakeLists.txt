##
# @file		CMakeLists.txt [/]
# @brief	Setup for and compile the shared library
#
# @author	sheltongabe		Gabriel Shelton
# @date 	2019-01-24

cmake_minimum_required(VERSION 2.8)

# For development only, comment when including as a library.
include(cmake/Root.cmake)

# Set library name
set(CPP_AI_LIB "cpp_ai")

# Make sure the compiler is at least c++14
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Start the project
project("${CPP_AI_LIB}")

# Allow for tests
include(CTest)

# Add the library
add_subdirectory(src)

# If testing is enabled, run tests
if(BUILD_TESTING)
	add_subdirectory(test/src)
endif()