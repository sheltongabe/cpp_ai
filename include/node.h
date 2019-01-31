/**
 * @file	node.h
 * @brief	Define the structure that holds data for the node
 * @details
 * Holds data for the search algorithms and is held by a graph
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	01-31-2019
 * @version	0.1
 */

#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class Edge;

/**
 * @class		Node
 * @brief		Stores data for searches and an id to the state it represents
 */
class Node {
	public:
		/// Id for this node
		std::string nodeId;

		/// Id of the graph this node belongs to
		std::string graphId;

		/// Id of the parent node (used during searches)
		std::string parentId;

		/// The cost to get to the origin of the search (used in searches)
		double costToOrigin;

		/// The Ids of the nodes that can be reached from this node
		std::vector<std::string> neighborEdgeIds;

		std::string stateId;

		/**
		 * @brief	Default Constructor
		 */
		Node();

		/**
		 * @brief	Copy Constructor
		 */
		Node(Node& copy);

		/**
		 * @brief	Move Constructor
		 */
		Node(Node&& original);

		/**
		 * @brief	Destructor
		 */
		~Node();

	private:

};

#include "edge.h"

#endif