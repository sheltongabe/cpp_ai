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



/**
 * @class	TextToGraphParser
 * @brief	Converts text to a Graph and can be done with an instance or a static method	
 */
template<typename State>
class TextToGraphParser {
	public:
		/**
		 * @brief	Default Constructor
		 */
		TextToGraphParser();

		/**
		 * @brief	Copy Constructor
		 */
		TextToGraphParser(TextToGraphParser& copy);

		/**
		 * @brief	Begin Parsing the text and build a Graph object to return
		 * @param	const std::string&	Text being converted
		 * @return	Graph<State>		Graph created from the text
		 */
		static Graph<State> parse(const std::string& text);

		/**
		 * @brief	Destructor
		 */
		~TextToGraphParser();

	private:

};

#endif