##
# @file 	CMakeLists.txt [/test/src]
# @brief	Build the test programs
#
# @author	sheltongabe		Gabriel Shelton
# @date		2019-01-24

set(EXE_NAME "${CPP_AI_LIB}_node_test")

project(${EXE_NAME})

# Include the src directory for now
include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/../include")

# Build the Executable
add_executable(${EXE_NAME}
	node_test.cpp
	graph_tester.cpp
	timer.cpp
	puzzle.cpp
)

# Link it
target_link_libraries(${EXE_NAME} "${CPP_AI_LIB}_static")

# Copy the puzzle graph structure to bin folder
file(COPY "data.dat" DESTINATION "${CMAKE_SOURCE_DIR}/bin")