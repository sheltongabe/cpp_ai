/**
 * @file	blind_search.cpp
 * @brief	Implement methods in BlindSearch
 * 
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-20-2019
 * @version	0.1
 */

#include <iostream>
#include <chrono>
#include <map>

// 
// breadthFirst(graph, getActions, goalTest)
//
template<typename State>
void BlindSearch<State>::breadthFirst(State graph, 
		std::function<std::vector<std::function<void(State&)>>(const State&)> getActions,
		std::function<bool(const State&)> goalTest) {
	// Set the root node to the initial state
	this->searchGraph.getNode("root").stateId = "initial";
	this->searchGraph.states["initial"] = graph;

	// Check if the initial state is a goal-state
	if(goalTest(graph)) {
		this->generateSolution("root");
		this->successful = true;
		return;
	}

	// Frontier with nodeIds from searchGraph
	std::deque<std::string> frontier;
	frontier.emplace_back("root");

	// Explored map with stateId's
	std::map<State, std::string> explored;

	// Record of a clock for outputing number of nodes every second
	auto clockStart = std::chrono::high_resolution_clock::now();
	int nodesPerSecond = 0;

	// Enter an infinite loop
	while(true) {
		// If the frontier is empty the search failed, return
		if(frontier.empty()) {
			this->successful = false;
			return;
		}

		// Grap the first node in the queue (adding it's state to explored) and expand
		auto clockCurrent = std::chrono::high_resolution_clock::now();
		if(std::chrono::duration_cast<std::chrono::milliseconds>(clockCurrent - clockStart).count() > 1000) {
			clockStart = clockCurrent;
			std::cout << "Frontier length: " << frontier.size() << " | Explored Size: " << 
					explored.size() << " | Nodes Per Second: " << nodesPerSecond << '\n';
			nodesPerSecond = 0;
		}
		auto& node = searchGraph.getNode(frontier.front()); frontier.pop_front();
		explored[this->searchGraph.states.at(node.stateId)] = node.stateId;

		auto actionList = getActions(this->searchGraph.states.at(node.stateId));
		for(auto action = actionList.begin(); action != actionList.end(); ++action) {
			// add create and add node to frontier adding the appropriate state
			State s(searchGraph.states.at(node.stateId));
			(*action)(s);
			int count = explored.count(s);

			if(count == 0) {
				const auto child = searchGraph.addNode(1.0, node.nodeId);
				this->searchGraph.addState(child, s);
				if(goalTest(s)) {
					this->generateSolution(child);
					this->successful = true;
					return;
				}
				frontier.emplace_back(child);
			}
		}
		++nodesPerSecond;
	}

}

// 
// generateSolution (std::string)
//
template<typename State>
void BlindSearch<State>::generateSolution(std::string nodeId) {
	// Get starting Node
	do {
		// Add action that prints the current Nodes state
		const auto& node = this->searchGraph.getNode(nodeId);
		const auto& s = this->searchGraph.states.at(node.stateId);
		nodeId = node.parentId;
		this->actions.emplace_back([s](State& dummy) {
			std::cout << s;
		});
	} while(nodeId != "");

	// Finally reverse the action queue
	std::reverse(this->actions.begin(), this->actions.end());
}

// 
// getAction()
//
template<typename State>
std::function<void(State&)> BlindSearch<State>::getAction() {
	auto action = this->actions.front(); this->actions.pop_front();
	return action;
}

// 
// hasAction()
//
template<typename State>
bool BlindSearch<State>::hasAction() {
	return this->actions.size() != 0;
}

// 
// wasSuccessful() -> bool
//
template<typename State>
bool BlindSearch<State>::wasSuccessful() {
	return this->successful;
}
