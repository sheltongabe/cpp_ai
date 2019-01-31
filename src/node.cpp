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
Node::Node(Node& copy) : 
		nodeId(copy.nodeId),
		graphId(copy.graphId),
		parentId(copy.parentId),
		costToOrigin(copy.costToOrigin),
		neighborEdgeIds(copy.neighborEdgeIds),
		stateId(copy.stateId) {

}

//
// Move Constructor
//
Node::Node(Node&& original) : 
		nodeId(std::move(original.nodeId)),
		graphId(std::move(original.graphId)),
		parentId(std::move(original.parentId)),
		costToOrigin(std::move(original.costToOrigin)),
		neighborEdgeIds(std::move(original.neighborEdgeIds)),
		stateId(std::move(original.stateId)) {

}

//
// Destructor 
//
Node::~Node() {

}