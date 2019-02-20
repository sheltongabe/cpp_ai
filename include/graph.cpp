/**
 * @file	graph.cpp
 * @brief	Implement methods defined in Graph
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-12-2019
 * @version	0.1
 */

//
// Default Constructor
//
template<typename State>
Graph<State>::Graph() :
		graphId("") {
	// Add root node
	Node n;
	n.graphId = this->graphId;
	n.nodeId = "root";
	n.stateId = "root";
	n.costToOrigin = 0;
	this->nodes[n.nodeId] = n;
}

//
// Copy Constructor
//
template<typename State>
Graph<State>::Graph(const Graph<State>& copy) :
		graphId(copy.graphId),
		nodes(copy.nodes),
		edges(copy.edges),
		states(copy.states) {

}

// 
// addNode(double, std::string, std::string) -> std::string
//
template<typename State>
std::string Graph<State>::addNode(double cost, std::string parentId, std::string nodeId) {
	Node n;
	n.graphId = this->graphId;
	n.parentId = parentId;
	n.nodeId = (nodeId != "") ? nodeId : "node_" + std::to_string(this->nextNodeId++);
	this->nodes[n.nodeId] = n;

	// Create an edge from parent to node along with the neighborEdge to parent
	this->addEdge(parentId, n.nodeId, cost);

	return n.nodeId;
}

// 
// addEdge(std::string, std::string, double, std::string) -> std::string
//
template<typename State>
std::string Graph<State>::addEdge(std::string source, std::string destination, double cost, std::string edgeId) {
	Edge e;
	e.graphId = this->graphId;
	e.edgeId = (edgeId != "") ? edgeId : "edge_" + std::to_string(this->nextEdgeId++);
	e.startNode = source;
	e.endNode = destination;
	e.cost = cost;
	this->edges[e.edgeId] = e;

	// Add neighbor to source
	auto& vec = this->getNode(e.startNode).neighborEdgeIds;
	vec.emplace_back(e.edgeId);


	return e.edgeId;
}

// 
// addState(std::string, std::string) -> std::string
//
template<typename State>
std::string Graph<State>::addState(std::string nodeId, State state, std::string stateId) {
	// generate StateId
	stateId = (stateId != "") ? stateId : "state_" + std::to_string(this->nextStateId++);

	this->states[stateId] = state;
	this->getNode(nodeId).stateId = stateId;

	return stateId;
}

// 
// getNode (std::string) -> Node&
//
template<typename State>
Node& Graph<State>::getNode(std::string nodeId) {
	return this->nodes.at(nodeId);
}

//
// getNode (std::string) -> Node
//
template<typename State>
Node Graph<State>::getNode(std::string nodeId) const {
	return this->nodes.at(nodeId);
}

// 
// getEdge (std::string) -> Edge&
//
template<typename State>
Edge& Graph<State>::getEdge(std::string edgeId) {
	return this->edges.at(edgeId);
}

// 
// getEdge (std::string) -> Edge
//
template<typename State>
Edge Graph<State>::getEdge(std::string edgeId) const {
	return this->edges.at(edgeId);
}

// 
// getState (std::string) -> State&
//
template<typename State>
State& Graph<State>::getState(std::string nodeId) {
	return this->states.at(this->getNode(nodeId).stateId);
}

// 
// getState (std::string) -> State
//
template<typename State>
State Graph<State>::getState(std::string nodeId) const {
	return this->states.at(this->getNode(nodeId).stateId);
}

// 
// operator==
//
template<typename State>
bool Graph<State>::operator==(const Graph<State>& rhs) {
	// Check self comparison
	if(this == &rhs)
		return true;
	
	// check id is equal
	if(this->graphId != rhs.graphId)
		return false;
	
	// check that all maps (node list, edge list, state list) are equal
	return this->nodes == rhs.nodes && 
			this->edges == rhs.edges && 
			this->states == rhs.states;
}

// 
// operator!=
//
template<typename State>
bool Graph<State>::operator!=(const Graph<State>& rhs) {
	return !(*this == rhs);
}
