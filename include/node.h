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

		/// Estimated cost from this node to goal (used by InformedSearch)
		double estimatedCost;

		/// The Ids of the nodes that can be reached from this node
		std::vector<std::string> neighborEdgeIds;

		/// Id of the state this node represents
		std::string stateId;

		friend inline bool operator<(const Node& lhs, const Node& rhs);
		friend inline bool operator==(const Node& lhs, const Node& rhs);
		friend inline bool operator!=(const Node& lhs, const Node& rhs);

	private:

};

inline bool operator<(const Node& lhs, const Node& rhs) {
	// Invert it to make sure the heap is ordered in min heap form during InformedSearches
	return !(lhs.estimatedCost < rhs.estimatedCost);
}

// 
// operator==
//
inline bool operator==(const Node& lhs, const Node& rhs) {
	// check self comparison
	if(&lhs == &rhs)
		return true;

	// Check against each property with a ternary operator
	bool equal = true;
	equal = (lhs.graphId == rhs.graphId) ? equal : false;
	equal = (lhs.nodeId == rhs.nodeId) ? equal : false;
	equal = (lhs.parentId == rhs.parentId) ? equal : false;
	equal = (lhs.costToOrigin == rhs.costToOrigin) ? equal : false;
	equal = (lhs.neighborEdgeIds == rhs.neighborEdgeIds) ? equal : false;
	equal = (lhs.stateId == rhs.stateId) ? equal : false;

	return equal;
}

// 
// operator!=
//
inline bool operator!=(const Node& lhs, const Node& rhs) {
	return !(lhs == rhs);
}

#include "edge.h"

#endif
