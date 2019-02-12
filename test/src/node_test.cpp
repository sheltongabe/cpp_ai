
#include <string>

#include <iostream>

#include "cpp_ai/graph_file_handler.h"
#include "cpp_ai/graph.h"

int main() {
	Graph<int> g;

	auto testGraph = GraphFileHandler<int>::readGraph("data.dat");

	//std::cout << "Graph ID: " << testGraph.graphId << '\n';
	//std::cout << "Node ID: " << testGraph.getNode("Hello Nodes").nodeId << '\n';

	return 0;
}