/**
 * @file	graph_tester.h
 * @brief	Test the methods and interactions of the Graph<State> class
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-18-2019
 * @version	0.1
 */

#ifndef GRAPH_TESTER_H
#define GRAPH_TESTER_H

#include <iostream>

#include "cpp_ai/graph_file_handler.h"
#include "cpp_ai/graph.h"

/**
 * @class		graph_tester
 * @brief		Test the graph class
 */
class GraphTester {
	public:
		/**
		 * @brief	Run test methods on the Graph class
		 */
		void test();

		/*
		 * @brief	Output the passed graph to the terminal
		 * @param	Graph<int>& 	Graph to print out
		 */
		void outputGraphText(Graph<int>& testGraph);

	private:
		bool testGraphCopy(Graph<int>& testGraph);
		bool testGraphAddNodeEdge();

};

#endif
