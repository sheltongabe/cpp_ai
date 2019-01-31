/**
 * @file	graph.cpp
 * @brief	Implement methods defined in Graph
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	01-31-2019
 * @version	0.1
 */

#include <utility>

//
// Default Constructor
//
template<typename State>
Graph<State>::Graph() :
		graphId("") {

}

//
// Copy Constructor
//
template<typename State>
Graph<State>::Graph(Graph& copy) :
		graphId(copy.graphId),
		nodes(copy.nodes),
		edges(copy.edges),
		states(copy.states) {

}

//
// Move Constructor
//
template<typename State>
Graph<State>::Graph(Graph&& original) :
		graphId(original.graphId), 
		nodes(std::move(original.nodes)),
		edges(std::move(original.edges)),
		states(std::move(original.states)) {

}

// 
// getNode (std::string) -> Node&
//
template<typename State>
Node& Graph<State>::getNode(std::string nodeId) {
	return this->nodes.at(nodeId);
}

//
// getNodeCopy (std::string) -> Node
//
template<typename State>
Node Graph<State>::getNodeCopy(std::string nodeId) {
	return this->nodes.at(nodeId);
}

// 
// getEdge (std::string) -> Edge&
//
template<typename State>
Edge& Graph<State>::getEdge(std::string nodeId) {
	return this->edges.at(nodeId);
}

// 
// getEdgeCopy (std::string) -> Edge
//
template<typename State>
Edge Graph<State>::getEdgeCopy(std::string edgeId) {
	return this->edges.at(edgeId);
}

//
// Destructor 
//
template<typename State>
Graph<State>::~Graph() {

}