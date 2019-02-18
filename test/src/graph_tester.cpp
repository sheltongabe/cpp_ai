/**
 * @file	graph_tester.cpp
 * @brief	Implementation for GraphTester methods
 *  
 * @author	Gabriel Shelton	sheltongabce
 * @date	02-18-2019
 * @version	0.1
 */

#include <algorithm>

#include "graph_tester.h"

// 
// test()
//
void GraphTester::test() {
	auto testGraph = GraphFileHandler<int>::readGraph("data.dat");
	outputGraphText(testGraph);

	// Begin tests
	std::cout << "Test Graph Copy: " << ((testGraphCopy(testGraph)) ? "passed" : "failed") << '\n';
	std::cout << "Test Add Node & edge: " << ((testGraphAddNodeEdge()) ? "passed" : "failed") << '\n';
}

// 
// testGraphCopy(Graph<int>&) -> bool
//
bool GraphTester::testGraphCopy(Graph<int>& testGraph) {
	Graph<int> copy(testGraph);
	return copy == testGraph;
}

// 
// testGraphAddNodeEdge() -> bool
//
bool GraphTester::testGraphAddNodeEdge() {
	Graph<std::string> g;
	bool passed = true;

	// Add an edge and node
	std::string nodeId = g.addNode(10);
	std::string edgeId = g.addEdge(nodeId, "root", 10);

	if(g.nodes.count(nodeId) == 0 ||
			g.edges.count(edgeId) == 0)
		return false;

	auto nodeEdgeIds = g.getNode(nodeId).neighborEdgeIds;
	if(std::find(nodeEdgeIds.begin(), nodeEdgeIds.end(), edgeId) == nodeEdgeIds.end())
		return false;
	
	if(g.getEdge(edgeId).cost != 10)
		return false;

	return passed;
}

// 
// outputGraphText(Graph<int>& graphTest)
//
void GraphTester::outputGraphText(Graph<int>& testGraph) {
	auto nodeMap = testGraph.nodes;
	auto edgeMap = testGraph.edges;

	std::cout << "Nodes:\n" << "--------------------\n";
	for(auto itr = nodeMap.begin(); itr != nodeMap.end(); ++itr) {
		std::cout << "NodeId: " << itr->second.nodeId << '\n';
		std::cout << "StateId: " << itr->second.stateId << '\n';
	}

	std::cout << "Edges:\n" << "--------------------\n";
	for(auto itr = edgeMap.begin(); itr != edgeMap.end(); ++itr) {
		std::cout << "EdgeId: " << itr->second.edgeId << '\n';
		std::cout << "Source: " << itr->second.startNode << '\n';
		std::cout << "Destination: " << itr->second.endNode << '\n';
		std::cout << "Cost: " << itr->second.cost << '\n';
	}
}
