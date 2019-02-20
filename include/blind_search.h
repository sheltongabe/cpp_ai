/**
 * @file	blind_search.h
 * @brief	Add methods to conduct blind searches
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-20-2019
 * @version	0.1
 */

#ifndef BLINDSEARCH_H
#define BLINDSEARCH_H

#include <functional>
#include <vector>
#include <deque>
#include <algorithm>

#include "graph.h"

/**
 * @class		BlindSearch
 * @brief		Conduct a blind search and get the next action
 */
template<typename State>
class BlindSearch {
	public:
		/**
		 * @brief	Conduct a breadth-first search
		 * @param	graph		The graph to search, in an initial state
		 * @param	getActions	A function to get the actions that can be taken from the current state
		 * @param	goalTest	Function to to test to see if the Graph is in a goal-state
		 */
		void breadthFirst(State graph, 
				std::function<std::vector<std::function<void(State&)>>(const State&)> getActions,
				std::function<bool(const State&)> goalTest);

		/**
		 * @brief	Get a solution by going reversing the tree and queuing actions.  It reverses it at the end
		 * @param	nodeId	Node to start at
		 */
		void generateSolution(std::string nodeId);

		/**
		 * @brief	Return whether or not a search was successful
		 * @return 	bool	Was the search successful
		 */
		bool wasSuccessful();

	private:
		/// Graph to hold search space
		Graph<State> searchGraph;

		/// Deque for actions to take after a successful search
		std::deque<std::function<void(State&)>> actions;

		/// was the search successful
		bool successful;
};

#include "blind_search.cpp"

#endif
