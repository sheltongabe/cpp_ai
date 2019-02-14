/**
 * @file	edge.h
 * @brief	Define the data structure that links the Nodes together
 *  
 * @author	Gabriel Sheltoni sheltongabe
 * @date	01-31-2019
 * @version	0.1
 */

#ifndef EDGE_H
#define EDGE_H

#include <string>

#include "node.h"

/**
 * @class		Edge
 * @brief		Links the Nodes together with one direction of flow
 */
class Edge {
	public:
		/// Id of the edge
		std::string edgeId;

		/// Id of graph 
		std::string graphId;

		/// The node where the edge starts
		std::string startNode;

		/// The node where the edge ends
		std::string endNode;

		/// The cost to travel along this node
		double cost;

		/**
		 * @brief	Default Constructor
		 */
		Edge();

		/**
		 * @brief	Copy Constructor
		 */
		Edge(const Edge& copy);

		/**
		 * @brief	Destructor
		 */
		~Edge();

		friend inline bool operator==(const Edge& lhs, const Edge& rhs);
		friend inline bool operator!=(const Edge& lhs, const Edge& rhs);

	private:

};

//
// operator==
//
inline bool operator==(const Edge& lhs, const Edge& rhs) {
	// Check self comparison
	if(&lhs == &rhs)
		return true;

	// Check each property
	bool equal = true;
	equal = (lhs.graphId == rhs.graphId) ? true : false;
	equal = (lhs.edgeId == rhs.edgeId) ? true : false;
	equal = (lhs.startNode == rhs.startNode) ? true : false;
	equal = (lhs.endNode == rhs.endNode) ? true : false;
	equal = (lhs.cost == rhs.cost) ? true : false;

	return equal;
}

// 
// operator!=
//
inline bool operator!=(const Edge& lhs, const Edge& rhs) {
	return !(lhs == rhs);
}

#endif