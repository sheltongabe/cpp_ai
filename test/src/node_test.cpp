
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

#include "cpp_ai/blind_search.h"

#include "graph_tester.h"
#include "puzzle.h"

/**
 * @brief	Test if the puzzle is in the goal state
 * @param	puzzle	The current state of the puzzle
 * @return	bool	If the puzzle is in a solved state
 */
bool goalTest(const Puzzle& puzzle);

/**
 * @brief	Generate a value that is estimating the distance to the goal
 * @param	puzzle	The state of the puzzle at this node
 * @return 	double	The estimated value (distance from goal)
 */
double heuristicFunction(const Puzzle& puzzle);

/**
 * @brief	Return the list of actions that can be taken from this state of the puzzle
 * @param	puzzle	The current State of the puzzle
 * @return 	std::vector<std::function<void(std::string)>>	List of actions
 */
std::vector<std::function<void(Puzzle&)>> getActions(const Puzzle& puzzle);

/// Solve a puzzle that is randomly generated
void solvePuzzle();

void testGraphClass();

int main() {
	testGraphClass();
	
	// Test solvePuzzle Items
	Puzzle p = Puzzle::getStructure("data.dat");
	std::cout << "Get Structure Test:\n" << p;
	
	Puzzle randomPuzzle = Puzzle::generateRandom();
	std::cout << "Generate Random Test:\n" << randomPuzzle;
	std::cout << "Goal Test: " << ((goalTest(p) && !goalTest(randomPuzzle)) ? "passed" : "failed") << '\n';

	std::cout << "Get Actions Test:\n" << randomPuzzle;
	auto actions = getActions(randomPuzzle);
	for(auto itr = actions.begin(); itr != actions.end(); ++itr) {
		Puzzle tmp(randomPuzzle);
		(*itr)(tmp);

		std::cout << "action: \n" << tmp;
	}

	solvePuzzle();

	return 0;
}

// 
// solvePuzzle()
//
void solvePuzzle() {
	// Generate the puzzle randomly
	Puzzle initialState = Puzzle::generateRandom();

	// create the std::functions to the traits for solving the problem
	std::function<bool(const Puzzle&)> goal = goalTest;
	std::function<double(const Puzzle&)> heuristic = heuristicFunction;
	std::function<std::vector<std::function<void(Puzzle&)>>(const Puzzle&)> actions = getActions;

	BlindSearch<Puzzle> blindSearch;
	blindSearch.breadthFirst(initialState, getActions, goalTest);
}

// 
// goalTest(const Puzzle&) -> bool
//
bool goalTest(const Puzzle& puzzle) {
	auto stateList = puzzle.getVector();
	
	// Is the list sorted till the last element
	bool sorted = std::is_sorted(stateList.begin(), stateList.end() - 1);

	// Check that the last element is zero
	sorted = (stateList[8] == 0) ? sorted : false;

	return sorted;
}

// 
// heuristicFunction(const Puzzle&) -> double
//
double heuristicFunction(const Puzzle& puzzle) {


	return 0.0;
}

// 
// getActions(const Puzzle&)
//
std::vector<std::function<void(Puzzle&)>> getActions(const Puzzle& puzzle) {
	// Vector of lamda's to hold
	std::vector<std::function<void(Puzzle& p)>> actions;

	// Blank Node
	const auto& blankNode = std::find_if(puzzle.nodes.begin(), puzzle.nodes.end(),
			[](const std::pair<std::string, Node> pair) -> bool {
		return pair.second.stateId == std::to_string(0);
	})->second;

	// loop through each neighboring edge and add an action swapping each
	auto neighbors = blankNode.neighborEdgeIds;
	for(auto itr = neighbors.begin(); itr != neighbors.end(); ++itr) {
		// Get starting and ending nodes; strip const because the action lambda needs to alter the puzzle
		const auto& startNodeId = puzzle.getEdge(*itr).startNode;
		const auto& endNodeId = puzzle.getEdge(*itr).endNode;

		// Add action to swap their states
		actions.emplace_back([startNodeId, endNodeId](Puzzle& p) {
			std::swap(p.getNode(startNodeId).stateId, p.getNode(endNodeId).stateId);
		});
	}

	return actions;
	}

void testGraphClass() {
	GraphTester graphTester;
	graphTester.test();
}
