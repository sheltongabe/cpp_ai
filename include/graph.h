/**
 * @file	graph.h
 * @brief	Define the data structure to store Nodes
 * @details
 * Search algorithms will manipulate the graph
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-02-2019
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
		 */
		Graph();

		/**
		 * @brief	Copy Constructor
		 */
		Graph(const Graph<State>& copy);

		/**
		 * @brief	Get a reference to a Node identified by nodeId
		 * @param	std::string		nodeId
		 * @return	Node&
		 */
		Node& getNode(std::string nodeId);

		/**
		 * @brief	Return a copy of a Node identified by nodeId
		 * @param	std::string		nodeId
		 * @return	Node
		 */
		Node getNodeCopy(std::string nodeId);

		/**
		 * @brief	Return a reference to an Edge identified by edgeId
		 * @param	std::string		edgeId
		 * @return	Edge&
		 */
		Edge& getEdge(std::string edgeId);

		/**
		 * @brief	Return a copy of an Edge identified by edgeId
		 * @param	std::string		edgeId
		 * @return	Edge
		 */
		Edge getEdgeCopy(std::string edgeId);
		
		/**
		 * @brief	Destructor
		 */
		~Graph();

	private:

};

#include "graph.cpp"

#endif