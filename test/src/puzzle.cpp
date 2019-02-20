/**
 * @file	puzzle.cpp
 * @brief	Implement methods in Puzzle
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-19-2019
 * @version	0.1
 */

#include <string>
#include <algorithm>
#include <random>

#include "puzzle.h"

// 
// Puzzle()
//
Puzzle::Puzzle() :
		Graph<int>() {

}

// 
// Puzzle(Graph<int>&)
//
Puzzle::Puzzle(Graph<int>& graph) :
		Graph<int>(graph) {

}

// 
// Puzzle(const Puzzle&)
//
Puzzle::Puzzle(const Puzzle& copy) :
		Graph<int>(copy) {

}

// 
// getStructure(std::string) -> Puzzle
//
Puzzle Puzzle::getStructure(std::string filename) {
	// Load the puzzle from a file
	auto graph = GraphFileHandler<int>::readGraph(filename);
	Puzzle puzzle(graph);
	auto& nodes = puzzle.nodes;

	// Add the integer states to the puzzle
	for(auto itr = nodes.begin(); itr != nodes.end(); ++itr) {
		// check that it is not the root node
		if(itr->first != "root")
			puzzle.states[itr->second.stateId] = std::stoi(itr->second.stateId);
	}

	return puzzle;
}

// 
// generateRandom() -> Puzzle
//
Puzzle Puzzle::generateRandom() {
	// Build puzzle structure
	Puzzle p = Puzzle::getStructure("data.dat");
    
	// get a vector and shuffle it
	auto vec = p.getVector();
	std::random_device rd;
    std::mt19937 generator(rd()); 
	std::shuffle(vec.begin(), vec.end(), generator);
	
	// Find and swap the 0 to the middle
	auto zeroLocation = std::find(vec.begin(), vec.end(), 0);
	std::swap(*(vec.begin() + 4), *zeroLocation);

	// Write the states in the vector to the Puzzle
	const std::string nodePrefix = "Node";
	for(int i = 0; i < 9; ++i)
		p.getNode(nodePrefix + std::to_string(i + 1)).stateId = std::to_string(vec[i]);

	return p;
}

// 
// getVector() -> std::vector<int>
//
std::vector<int> Puzzle::getVector() const {
	// vector to return
	std::vector<int> toReturn;

	// Prefix of Node key
	const std::string nodePrefix = "Node";

	// Loop through, construct the string (key) 
	// and add value to vector
	for(int i = 1; i <= 9; ++i) {
		auto node = this->getNode(nodePrefix + std::to_string(i));
		toReturn.emplace_back(this->getState(nodePrefix + std::to_string(i)));
	}
	
	return toReturn;
}

// 
// operator<<(std::ostream&, const Puzzle&)
//
std::ostream& operator<<(std::ostream& os, const Puzzle& puzzle) {
	// Grab a vector version of the puzzle
	auto vec = puzzle.getVector();

	// loop through the vector and print it out in three rows
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			os << " " << vec[3 * i + j];
		}
		os << '\n';
	}

	return os;
}
