/**
 * @file	file_handler.cpp
 * @brief	Implement the methods defined in FileHandler
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-05-2019
 * @version	0.1
 */

#include <fstream>
#include <sstream>
#include <exception>
#include <iostream>

#include "file_handler.h"

// 
// readFile (const std::string&) -> std::string
//
std::string FileHandler::readFile(const std::string& filename) {
	// Hold the output
	std::stringstream fileData;
	fileData.clear();

	// Open and prepare to read the file
	try {
		// buffer
		std::string line;
		std::ifstream file(filename.c_str());

		// Input the file until the end is hit
		while(!file.eof()) {
			file >> line;
			fileData << line;
		}
		file.close();
	}
	catch(std::exception e) {
		std::cout << "Failed to read file: " << filename << '\n';
		throw e;
	}

	// No error
	return fileData.str();
}

// 
// writeFile (const std::string&, const std::string&) -> void
//
void FileHandler::writeFile(const std::string& filename, const std::string& data) {
	// Try to Open the file
	try {
		std::ofstream file(filename.c_str(), std::ofstream::out);
		file << data;
		file.close();
	}
	catch(std::exception e) {
		std::cout << "Failed to write to file: " << filename << '\n';
		throw e;
	}
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
