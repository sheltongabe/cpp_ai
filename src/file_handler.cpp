/**
 * @file	file_handler.cpp
 * @brief	Implement the methods defined in FileHandler
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-05-2019
 * @version	0.1
 */

#include "file_handler.h"

//
// Default Constructor
//
FileHandler::FileHandler() {

}

//
// Copy Constructor
//
FileHandler::FileHandler(FileHandler& copy) {

}

// 
// readFile (const std::string&) -> std::string
//
std::string FileHandler::readFile(const std::string& filename) {

}

// 
// writeFile (const std::string&, const std::string&) -> void
//
void FileHandler::writeFile(const std::string& filename, const std::string& data) {

}

// 
// addFileExtension (std::string&, const std::string&) -> void
//
void FileHandler::addFileExtension(std::string& filename, const std::string& extension) {
	// Get the position of the extension starting from the end
	const size_t lastPos = filename.rfind(extension);

	// If the extension is not here or not at the end, add it
	if(lastPos == std::string::npos ||
			filename.length() - extension.length() != lastPos) {
		// Add the extension
		filename += extension;
	}
}

//
// Destructor 
//
FileHandler::~FileHandler() {

}