

#include "timer.h"

// 
// Default Constructor
//
Timer::Timer() :
		start(std::chrono::high_resolution_clock::now()) {

}

// 
// Copy Constructor
//
Timer::Timer(Timer& t) :
		start(t.start) {

}

// 
// Move Constructor
//
Timer::Timer(Timer&& t) :
		start(std::move(t.start)) {
}

// 
// startTime
//
void Timer::startTimer() {
	this->start = std::chrono::high_resolution_clock::now();
}

// 
// timeElapsed
//
long long Timer::timeElapsed() {
	auto diff = std::chrono::high_resolution_clock::now() - start;

	// use the difference from now and start to figure elapsed time
	return std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
}

//
// Destructor
//
Timer::~Timer() {

}