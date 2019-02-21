#ifndef TIMER_H
#define TIMER_H

#include <utility>
#include <chrono>

/**
 * @class 	Timer
 * @brief	used to time the execution of a part of
 * 			code in micro_seconds
 */
class Timer {
	public:
		/**
		 * @brief	Default Constructor
		 */
		Timer();

		/**
		 * @brief				Copy Constructor
		 * @param	Timer& 		Object to copy
		 */
		Timer(Timer& t);

		/**
		 * @brief				Move Constructor
		 * @param	Timer&& 	address of object to move vars from
		 */
		Timer(Timer&& t);

		/**
		 * @brief	Start the timer
		 */
		void startTimer();

		/**
		 * @brief	Return the time elapsed in micro-seconds
		 * @return	Time elapsed in micro-seconds since last call to 
		 * 			startTimer
		 */
		long long timeElapsed();

		/**
		 * @brief	Destructor
		 */
		~Timer();

	private:
		/// Time point representing when the timer was started
		std::chrono::high_resolution_clock::time_point start;
};

#endif