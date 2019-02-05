/**
 * @file	state_fil_hHandler.h
 * @brief	
 *  
 * Details
 *  
 * @author	First_Last_Name	username
 * @date	02-05-2019
 * @version	0.0
 */

#ifndef STATEFILEHANDLER_H
#define STATEFILEHANDLER_H



/**
 * @class		StateFileHandler
 * @brief		
 * 
 * Details
 * 
 */
class StateFileHandler {
	public:
		/**
		 * @brief	Default Constructor
		 */
		StateFileHandler();

		/**
		 * @brief	Copy Constructor
		 */
		StateFileHandler(StateFileHandler& copy);

		/**
		 * @brief	Move Constructor
		 */
		StateFileHandler(StateFileHandler&& original);

		/**
		 * @brief	Destructor
		 */
		~StateFileHandler();

	private:

};

#endif