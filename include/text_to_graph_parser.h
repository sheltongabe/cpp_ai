/**
 * @file	text_to_graph_parser.h
 * @brief	Define a class that converts text to a Graph
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	02-05-2019
 * @version	0.1
 */

#ifndef TEXT_TO_GRAPH_PARSER_H
#define TEXT_TO_GRAPH_PARSER_H

#include <string>
#include <sstream>

#include "graph.h"

/**
 * @class	TextToGraphParser
 * @brief	Converts text to a Graph and can be done with an instance or a static method	
 */
template<typename State>
class TextToGraphParser {
	public:		/**
		 * @brief	Begin Parsing the text and build a Graph object to return
		 * @param	text	Text being converted
		 * @return	Graph<State>		Graph created from the text
		 */
		static Graph<State> parse(const std::string& text);

	private:
		/**
		 * @brief	Read in the nodes from the string stream and add to graph
		 * @param	text	Text being converted, in the form of a stringstream
		 * @param	graph	Graph to store to
		 */
		static void readNodes(std::stringstream& text, Graph<State>& graph);

		/**
		 * @brief	Read in the edges from the string stream and add to graph
		 * @param	text	Text being converted, in the form of a stringstream
		 * @param	graph	Graph to store to
		 */
		static void readEdges(std::stringstream& text, Graph<State>& graph);

		/**
		 * @brief	Read a label up to the delemiter then store the property
		 * @param	text		Text being converted, in the form of a stringstream
		 * @param 	property	String to store property to
		 * @param	delimeter	How to tell when the key ends and value starts
		 */
		static void readProperty(std::stringstream& text, std::string& property, const char delimeter = '=');
};

#include "text_to_graph_parser.cpp"

#endif
