/**
 * @file	graph.h
 * @brief	Define the data structure to store Nodes
 * @details
 * Search algorithms will manipulate the graph
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-12-2019
 * @version	0.1
 */

#ifndef GRAPH_H
#define GRAPH_H

#include<string>
#include<map>

#include "node.h"

/**
 * @class		Graph
 * @brief		A data structure that stores nodes, edges, and states
 * @details
 * Other algorithms are responsible for manipulating this data structure.
 */
template<typename State>
class Graph {
	public:
		/// Id for the graph
		std::string graphId;

		/// Map of Nodes indexed by strings
		std::map<std::string, Node> nodes;

		/// Map of Edges indexed by strings
		std::map<std::string, Edge> edges;

		/// Map of States indexed by strings
		std::map<std::string, State> states;

		/**
		 * @brief	Default Constructor
		 * @details
		 * Also creates a root node for other nodes to be based from
		 */
		Graph();

		/**
		 * @brief	Copy Constructor
		 */
		Graph(const Graph<State>& copy);

		/**
		 * @brief	Add a node to the graph
		 * @param	parentId		Id of the parent node = "root"
		 * @param	cost			Cost to get to this node
		 * @param	nodeId			Id of the node to make = ""
		 * @return	std::string		NodeId
		 * @details
		 * There is always going to be a start node called root to build your graph off of
		 * and if you don't specify a parent for the node then it will be set to root.
		 */
		std::string addNode(double cost, std::string parentId = "root", std::string nodeId = "");

		/**
		 * @brief	Add an Edge and will also adjust the neighboring nodes.
		 * @param	sourceId		Which node to start from
		 * @param	destinationId	Node to go to
		 * @param	cost 			Cost to traverse between nodes
		 * @param	edgeId			Id of this edge = ""
		 * @return	std::string		EdgeId
		 */
		std::string addEdge(std::string sourceId, std::string destinationId, double cost, std::string edgeId = "");

		/**
		 * @brief	Get a reference to a Node identified by nodeId
		 * @param	nodeId	Which node to get
		 * @return	Node&
		 */
		Node& getNode(std::string nodeId);

		/**
		 * @brief	Return a copy of a Node identified by nodeId
		 * @param	nodeId	Which node to get
		 * @return	Node
		 */
		Node getNode(std::string nodeId) const;

		/**
		 * @brief	Return a reference to an Edge identified by edgeId
		 * @param	edgeId	Which edge to get
		 * @return	Edge&
		 */
		Edge& getEdge(std::string edgeId);

		/**
		 * @brief	Return a copy of an Edge identified by edgeId
		 * @param	edgeId which edge to get
		 * @return	Edge
		 */
		Edge getEdge(std::string edgeId) const;

		/**
		 * @brief	Return a reference to an State identified by nodeId
		 * @param	nodeId	Which edge to get
		 * @return	State&
		 */
		State& getState(std::string nodeId);

		/**
		 * @brief	Return a copy of a State identified by nodeId
		 * @param	nodeId 	which edge to get
		 * @return	State
		 */
		State getState(std::string nodeId) const;

		bool operator==(const Graph<State>& rhs);
		bool operator!=(const Graph<State>& rhs);

	private:
		/// Next numerical id to use for a node number
		int nextNodeId = 0;

		/// Next numerical id to use for a edge number
		int nextEdgeId = 0;
};

#include "graph.cpp"

#endif
