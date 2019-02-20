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
				std::function<double(const Puzzle&)> heuristic);

	private:

};

#include "informed_search.cpp"

#endif