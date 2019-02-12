##
# @file		CMakeLists.txt [/src]
# @brief	Build the library
#
# @author	sheltongabe		Gabriel Shelton
# @date		2019-01-24

# Deal with headers
set(DIR_NAME ${CMAKE_SOURCE_DIR}/include/${CPP_AI_LIB})
include(${CMAKE_SOURCE_DIR}/cmake/CopyHeaders.cmake)

# Set Sources
set(LIB_SOURCES
	"edge.cpp"
	"node.cpp"
	"file_handler.cpp"
)

# Add shared Library
add_library("${CPP_AI_LIB}_static" STATIC ${LIB_SOURCES})