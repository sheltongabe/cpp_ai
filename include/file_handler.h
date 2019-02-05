/**
 * @file	file_handler.h
 * @brief	Define a class that handles file input or output
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-05-2019
 * @version	0.1
 */

#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>

/**
 * @class		FileHandler
 * @brief		Handles any file input or output and permits checking of file extensions for its children
 * @details		Also allows reading files with static methods or user can create a version of the class and use it
 */
class FileHandler {
	public:
		/**
		 * @brief	Default Constructor
		 */
		FileHandler();

		/**
		 * @brief	Copy Constructor
		 */
		FileHandler(FileHandler& copy);

		/**
		 * @brief	Read the file specified in filename
		 * @param	const std::string&	Filename
		 * @return	std::string			File data
		 */
		static std::string readFile(const std::string& filename);

		/**
		 * @brief	write the data to the file specified in filename
		 * @param	const std::string&	Filename
		 * @param	const std::string& 	Data
		 */
		static void writeFile(const std::string& filename, const std::string& data);

		/**
		 * @brief	Destructor
		 */
		~FileHandler();

	protected:
		/**
		 * @brief	Add a file extension if it is missing to filename
		 * @param	std::string&		filename
		 * @param	const std::string&	extension
		 */
		static void addFileExtension(std::string& filename, const std::string& extension);

};

#endif