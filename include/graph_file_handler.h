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
#include "text_to_graph_parser.h"
#include "graph.h"

/**
 * @class	GraphFileHandler
 * @brief	Read in and write out files for graphs
 */
template<typename State>
class GraphFileHandler : public FileHandler {
	public:
		GraphFileHandler();
		GraphFileHandler(GraphFileHandler<State>& copy);
		
		/**
		 * @brief	Read in a file with FileHandler and convert it to a Graph
		 * @param	filename		Name of the file to read
		 * @return 	Graph<State>	A Graph made from the data in the file
		 */
		static Graph<State> readGraph(std::string filename);

		/**
		 * @brief	Write a Graph<State> to a file
		 * @param	filename	Name of the file to write to
		 * @param	graph		Graph to write to a file
		 */
		static void writeGraph(std::string filename, Graph<State>& graph);

		~GraphFileHandler();

	private:
		/// File extension for Graph files
		static const std::string FILE_EXTENSION;
};

#include "graph_file_handler.cpp"

#endif
