/**
 * @file	graph_file_handler.cpp
 * @brief	Implement methods declared in GraphFileHandler
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-05-2019
 * @version	0.1
 */

#include "graph_file_handler.h"

//
// Default Constructor
//
GraphFileHandler::GraphFileHandler() : 
		FileHandler() {

}

//
// Copy Constructor
//
GraphFileHandler::GraphFileHandler(GraphFileHandler& copy) :
		FileHandler(copy) {

}

// 
// readGraph (std::string) -> Graph<State>
//
template<typename State>
Graph<State> GraphFileHandler::readGraph(std::string filename) {
	// Add file extension if needed
	GraphFileHandler::addFileExtension(filename, GraphFileHandler::FILE_EXTENSION);
	
}

// 
// writeGraph (std::string, Graph<State>&) -> void
//
template<typename State>
void GraphFileHandler::writeGraph(std::string filename, Graph<State>& graph) {
	// Add file extension if needed
	GraphFileHandler::addFileExtension(filename, GraphFileHandler::FILE_EXTENSION);

}

//
// Destructor 
//
GraphFileHandler::~GraphFileHandler() :
		~FileHandler() {

}