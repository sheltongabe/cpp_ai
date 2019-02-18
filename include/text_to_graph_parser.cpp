/**
 * @file	text_to_graph_parser.cpp
 * @brief	Implement methods defined in TextToGraphParser
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-06-2019
 * @version	0.1
 */

//
// Default Constructor
//
template<typename State>
TextToGraphParser<State>::TextToGraphParser() {

}

//
// Copy Constructor
//
template<typename State>
TextToGraphParser<State>::TextToGraphParser(TextToGraphParser<State>& copy) {

}

// 
// parse(const std::string&) -> Graph<State>
//
template<typename State>
Graph<State> TextToGraphParser<State>::parse(const std::string& text) {
	// Graph to return, and string stream for data
	Graph<State> graph;
	std::stringstream s;
	s.clear();
	s << text;

	// Read in id and set
	readProperty(s, graph.graphId);
	// Ignore -
	s.get();

	// Read Nodes and add to graph
	readNodes(s, graph);

	// Read Edges and add to graph
	readEdges(s, graph);

	return graph;
}

//
// readNodes(std::stringstream&, Graph<State>&) -> void
//
template<typename State>
void TextToGraphParser<State>::readNodes(std::stringstream& text, Graph<State>& graph) {
	// String to use as a buffer for reading from text
	std::string buffer = "";

	// Read in the Dummy Nodes label
	std::getline(text, buffer, '-');
	
	// Loop till Done
	while(text.peek() != '-') {
		// Create a tempory node
		Node tmpNode;

		// Read and set nodeId
		readProperty(text, tmpNode.nodeId);

		// Read and set node's stateId
		readProperty(text, tmpNode.stateId);

		// Add tmpNode to graph
		graph.nodes[tmpNode.nodeId] = tmpNode;

		// Consume marker for end of Node
		std::getline(text, buffer, '-');
	}
	text.get();
}

//
// readEdges(std::stringstream&, Graph<State>&) -> void
//
template<typename State>
void TextToGraphParser<State>::readEdges(std::stringstream& text, Graph<State>& graph) {
	// String to use as a buffer for reading from text
	std::string buffer = "";

	// Read in the Dummy Edges label
	std::getline(text, buffer, '-');
	
	// Loop till Done
	while(text.peek() != '-') {
		// Create a tempory Edge
		Edge tmpEdge;

		// Read and set data for edges starting with edgeId
		readProperty(text, tmpEdge.edgeId);
		readProperty(text, tmpEdge.startNode);
		readProperty(text, tmpEdge.endNode);
		readProperty(text, buffer);
		tmpEdge.cost = std::stod(buffer);

		// Add tmpNode to graph
		graph.edges[tmpEdge.edgeId] = tmpEdge;
		graph.getNode(tmpEdge.startNode).neighborEdgeIds.emplace_back(tmpEdge.edgeId);

		// Consume marker for end of Edge
		std::getline(text, buffer, '-');
	}
	text.get();
}

// 
// readProperty(std::stringstream&, std::string&, const char)
//
template<typename State>
void TextToGraphParser<State>::readProperty(
		std::stringstream& text, std::string& property, const char delimeter) {
	// Read up to the delimiter and store it in property temporarily
	std::getline(text, property, delimeter);

	// Read in the property till a '|' is next
	property = "";
	while(text.peek() != '|') {
		property += text.get();
	}
}

//
// Destructor 
//
template<typename State>
TextToGraphParser<State>::~TextToGraphParser() {

}