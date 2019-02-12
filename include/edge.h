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

	private:

};

#endif