/**
 * @file	graph_file_handler.cpp
 * @brief	Implement methods declared in GraphFileHandler
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-05-2019
 * @version	0.1
 */

template<typename State>
const std::string GraphFileHandler<State>::FILE_EXTENSION = ".dat";

//
// Default Constructor
//
template<typename State>
GraphFileHandler<State>::GraphFileHandler() : 
		FileHandler() {

}

//
// Copy Constructor
//
template<typename State>
GraphFileHandler<State>::GraphFileHandler(GraphFileHandler<State>& copy) :
		FileHandler(copy) {

}

// 
// readGraph (std::string) -> Graph<State>
//
template<typename State>
Graph<State> GraphFileHandler<State>::readGraph(std::string filename) {
	// Add file extension if needed
	GraphFileHandler::addFileExtension(filename, GraphFileHandler::FILE_EXTENSION);
	
	// read the file and store it to text
	std::string text = FileHandler::readFile(filename);

	// Parse it into a graph and return
	 return TextToGraphParser<State>::parse(text);
}

// 
// writeGraph (std::string, Graph<State>&) -> void
//
template<typename State>
void GraphFileHandler<State>::writeGraph(std::string filename, Graph<State>& graph) {
	// Add file extension if needed
	GraphFileHandler::addFileExtension(filename, GraphFileHandler::FILE_EXTENSION);

}

//
// Destructor 
//
template<typename State>
GraphFileHandler<State>::~GraphFileHandler() {

}