##
# @file		CMakeLists.txt [/src]
# @brief	Build the library
#
# @author	sheltongabe		Gabriel Shelton
# @date		2019-01-24

# Deal with headers

# Set Sources
set(LIB_SOURCES
	"hello_world.cpp"
)

# Add shared Library
add_library("${CPP_AI_LIB}_static" STATIC ${LIB_SOURCES})