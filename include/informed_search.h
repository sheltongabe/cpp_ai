/**
 * @file	informed_search.h
 * @brief	Implement informed search algorithms similiar to blind search algorithms
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-20-2019
 * @version	0.1
 */

#ifndef INFORMED_SEARCH_H
#define INFORMED_SEARCH_H

#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>

#include "graph.h"

/**
 * @class		InformedSearch
 * @brief		Search algorithms that use a heuristic
 */
template<typename State>
class InformedSearch {
	public:
		/**
		 * @brief	A* search algorithm
		 * @param	initialState	The initial State of the graph to search
		 * @param	getActions		Function to get Actions
		 * @param	goalTest		Function to test if a State is in the goal state
		 * @param	heuristic		Function that gets the predicted cost to the goal
		 */
		void aStar(State initialState,
				std::function<std::vector<std::function<void(State&)>>(const State&)> getActions,
				std::function<bool(const State&)> goalTest,
				std::function<double(const State&)> heuristic);

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

		/// Remove an action from the front of the actions deque and return it
		std::function<void(State&)> getAction();

		/// Is there an action remaining in the actions deque
		bool hasAction();

	private:
		/// Graph to use for search
		Graph<State> searchGraph;

		/// deque of actions after a successful search
		std::deque<std::function<void(State&)>> actions;

		/// Was the search successful
		bool successful;

};

#include "informed_search.cpp"

#endif
