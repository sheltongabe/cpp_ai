/**
 * @file	informed_search.cpp
 * @brief	Implement methods in InformedSearch
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-20-2019
 * @version	0.1
 */

#include <iostream>
#include <chrono>

// 
// aStar()
//
template<typename State>
void InformedSearch<State>::aStar(State initialState,
		std::function<std::vector<std::function<void(State&)>>(const State&)> getActions,
		std::function<bool(const State&)> goalTest,
		std::function<double(const State&)> heuristic) {
	// Set the root node to the initial state
	this->searchGraph.getNode("root").stateId = "initial";
	this->searchGraph.states["initial"] = initialState;

	// Check if the initial state is a goal-state
	if(goalTest(initialState)) {
		this->generateSolution("root");
		this->successful = true;
		return;
	}

	// generate the frontier in the form of a vector which will be a heap
	std::vector<Node> frontier;
	std::make_heap(frontier.begin(), frontier.end());
	frontier.push_back(this->searchGraph.getNode("root")); std::push_heap(frontier.begin(), frontier.end());

	// Explored List
	std::map<State, std::string> explored;

	//auto clockStart = std::chrono::high_resolution_clock::now();
	// int nodesPerSecond = 0;

	while(true) {
		// If the frontier is empty the search failed, return
		if(frontier.empty()) {
			this->successful = false;
			return;
		}

		auto node = (frontier.front()); 
		std::pop_heap(frontier.begin(), frontier.end()); frontier.pop_back();
		explored[this->searchGraph.states.at(node.stateId)] = node.stateId;

		auto actionList = getActions(this->searchGraph.states.at(node.stateId));
		for(auto action = actionList.begin(); action != actionList.end(); ++action) {
			// add create and add node to frontier adding the appropriate state
			State s(searchGraph.states.at(node.stateId));
			(*action)(s);
			int count = explored.count(s);

			if(count == 0) {
				double cost = heuristic(s);
				const auto child = searchGraph.addNode(cost, node.nodeId);
				auto& childNode = this->searchGraph.getNode(child);
				childNode.costToOrigin = node.costToOrigin + 1;
				childNode.estimatedCost = cost + childNode.costToOrigin;

				this->searchGraph.addState(child, s);
				if(goalTest(s)) {
					this->generateSolution(child);
					this->successful = true;
					return;
				}
				frontier.push_back(childNode); std::push_heap(frontier.begin(), frontier.end());
			}
		}
		// ++nodesPerSecond;
	}
}



// 
// generateSolution (std::string)
//
template<typename State>
void InformedSearch<State>::generateSolution(std::string nodeId) {
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
std::function<void(State&)> InformedSearch<State>::getAction() {
	auto action = this->actions.front(); this->actions.pop_front();
	return action;
}

// 
// hasAction()
//
template<typename State>
bool InformedSearch<State>::hasAction() {
	return this->actions.size() != 0;
}

// 
// wasSuccessful() -> bool
//
template<typename State>
bool InformedSearch<State>::wasSuccessful() {
	return this->successful;
}
