/**
 * @file	node.cpp
 * @brief	Implement the methods in Node class
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	01-31-2019
 * @version	0.1
 */

#include <utility>

#include "node.h"

//
// Default Constructor
//
Node::Node() : 
		nodeId(""),
		graphId(""),
		parentId(""),
		costToOrigin(0.0),
		stateId("") {

}

//
// Copy Constructor
//
Node::Node(const Node& copy) : 
		nodeId(copy.nodeId),
		graphId(copy.graphId),
		parentId(copy.parentId),
		costToOrigin(copy.costToOrigin),
		neighborEdgeIds(copy.neighborEdgeIds),
		stateId(copy.stateId) {

}

//
// Destructor 
//
Node::~Node() {

}