/**
 * @file	graph_to_text_parser.h
 * @brief	Implement a parser that converts a graph to the text to be outputed to a file
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-05-2019
 * @version	0.1
 */

#ifndef GRAPH_TO_TEXT_PARSER_H
#define GRAPH_TO_TEXT_PARSER_H

#include "graph.h"

/**
 * @class	GraphToTextParser
 * @brief	A parser that converts a graph to text in the file format
 * @details
 * Can be ran with a static method or as an instance of an object
 */
template<typename State>
class GraphToTextParser {
	public:		/**
		 * @brief	Begin parsing the Graph into a string of data for output
		 * @param	graph			Graph to parse
		 * @return	std::string		Data after parsing
		 */
		static std::string parse(const Graph<State>& graph);

	private:

};

#endif
