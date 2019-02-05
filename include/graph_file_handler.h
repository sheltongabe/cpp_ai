/**
 * @file	graph_file_handler.h
 * @brief	Define a class that reads and writes graphs from a file
 * @details
 * You can use either static methods or create an instance of the class
 * 
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-05-2019
 * @version	0.1
 */

#ifndef GRAPH_FILE_HANDLER_H
#define GRAPH_FILE_HANDLER_H

#include "file_handler.h"
#include "graph.h"

/**
 * @class	GraphFileHandler
 * @brief	Read in and write out files for graphs
 */
class GraphFileHandler : public FileHandler {
	public:
		/**
		 * @brief	Default Constructor
		 */
		GraphFileHandler();

		/**
		 * @brief	Copy Constructor
		 */
		GraphFileHandler(GraphFileHandler& copy);

		/**
		 * @brief	Read in a file with FileHandler and convert it to a Graph
		 * @param	std::string		Filename
		 * @return 	Graph<State>	A Graph made from the data in the file
		 */
		template<typename State>
		static Graph<State> readGraph(std::string filename);

		/**
		 * @brief	Write a Graph<State> to a file
		 * @param	std::string		Filename
		 * @param	Graph<State>	Graph to write
		 */
		template<typename State>
		static void writeGraph(std::string filename, Graph<State>& graph);

		/**
		 * @brief	Destructor
		 */
		~GraphFileHandler();

	private:
		/// File extension for Graph files
		static const std::string FILE_EXTENSION;
};

const std::string GraphFileHandler::FILE_EXTENSION = ".dat";

#endif