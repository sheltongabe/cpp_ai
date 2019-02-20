/**
 * @file	puzzle.h
 * @brief	Implement an instance of the puzzle
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-19-2019
 * @version	0.1
 */

#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>

#include "cpp_ai/graph.h"
#include "cpp_ai/graph_file_handler.h"

/**
 * @class		Puzzle
 * @brief		Defines a version of the 8-puzzle
 */
class Puzzle : public Graph<int> {
	public:
		/// Defualt Constructor
		Puzzle();

		/// Initializing Constructor
		Puzzle(Graph<int>& graph);

		/// Copy constructor
		Puzzle(const Puzzle& copy);
	
		/**
		 * @brief	Input the structure of the Graph from a file
		 * @param	filename	Name of the file containing the graph structure
		 * @return	Puzzle		The puzzle graph structure
		 */
		static Puzzle getStructure(std::string filename);

		/**
		 * @brief	Generate a random puzzle and return it
		 * @return	Puzzle
		 * */
		static Puzzle generateRandom();

		/**
		 * @brief	Convert the puzzle into a vector form and return
		 * @details
		 * The vector will be 9 long and 0 will mark the blank space
		 * @return	std::vector<int>	A list of the values in the puzzle left to right
		 */
		std::vector<int> getVector() const;

		friend bool operator<(const Puzzle& lhs, const Puzzle& rhs);
		friend bool operator==(const Puzzle& lhs, const Puzzle& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Puzzle& puzzle);

	private:

};

#endif
