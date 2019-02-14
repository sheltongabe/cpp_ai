
#include <string>

#include <iostream>

#include "cpp_ai/graph_file_handler.h"
#include "cpp_ai/graph.h"

bool outputGraphText(Graph<int>& testGraph);
bool testGraphCopy(Graph<int>& testGraph);

int main() {
	auto testGraph = GraphFileHandler<int>::readGraph("data.dat");
	outputGraphText(testGraph);

	// Begin tests
	std::cout << "Test Graph Copy: " << ((testGraphCopy(testGraph)) ? "passed" : "failed") << '\n';

	return 0;
}

bool outputGraphText(Graph<int>& testGraph) {
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
	return true;
}

bool testGraphCopy(Graph<int>& testGraph) {
	Graph<int> copy(testGraph);
	return copy == testGraph;
}