/**
 * @file	edge.cpp
 * @brief	implement methods in edge header
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	01-31-2019
 * @version	0.1
 */

#include <utility>

#include "edge.h"

//
// Default Constructor
//
Edge::Edge() : 
		edgeId(""),
		graphId(""),
		startNode(""),
		endNode(""),
		cost(0.0) {
}

//
// Copy Constructor
//
Edge::Edge(Edge& copy) : 
		edgeId(copy.edgeId),
		graphId(copy.graphId),
		startNode(copy.startNode),
		endNode(copy.endNode),
		cost(copy.cost) {

}

//
// Move Constructor
//
Edge::Edge(Edge&& original) : 
		edgeId(std::move(original.edgeId)),
		graphId(std::move(original.graphId)),
		startNode(std::move(original.startNode)),
		endNode(std::move(original.endNode)),
		cost(std::move(original.cost)) {

}

//
// Destructor 
//
Edge::~Edge() {

}