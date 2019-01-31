##
# @file		CopyHeaders.cmake
# @brief	Copies the headers from the include directory to the library directory
#
# @author	sheltongabe		Gabriel Shelton
# @date		2019-01-31

# Set the path to the headers
set(HEADERS_DIR ${PROJECT_SOURCE_DIR}/include)

# Include the Headers
include_directories(${HEADERS_DIR})

# Build a folder for the headers in the root cmake include directory and copy headers in
file(MAKE_DIRECTORY ${DIR_NAME})
file(GLOB LIB_HEADERS ${HEADERS_DIR}/*.h ${HEADERS_DIR}/*.cpp)
file(COPY ${LIB_HEADERS} DESTINATION ${DIR_NAME})