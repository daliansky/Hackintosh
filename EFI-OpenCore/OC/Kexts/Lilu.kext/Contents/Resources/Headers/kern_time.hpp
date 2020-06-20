//
//  kern_time.hpp
//  Lilu
//
//  Copyright © 2018 vit9696. All rights reserved.
//

#ifndef kern_time_hpp
#define kern_time_hpp

#include <kern/clock.h>

/**
 *  Obtain current system time in nanoseconds
 *
 *  @return current time
 */
inline uint64_t getCurrentTimeNs() {
	uint64_t currt = 0;
	absolutetime_to_nanoseconds(mach_absolute_time(), &currt);
	return currt;
}

/**
 *  Obtain current calendar system time in nanoseconds
 *
 *  @return current time
 */
inline uint64_t getCalendarTimeNs() {
	clock_sec_t sc;
	clock_nsec_t ns;
	clock_get_calendar_nanotime(&sc, &ns);
	return static_cast<uint64_t>(sc) * NSEC_PER_SEC + ns;
}

/**
 *  Obtain time passed since some timestamp in nanoseconds
 *
 *  @param start   starting timestamp
 *  @param current timestamp to check against (pass 0 for current time)
 *
 *  @return delta or 0 (if current time equals or precedeces the start)
 */
inline uint64_t getTimeSinceNs(uint64_t start, uint64_t current = 0) {
	if (current == 0)
		current = getCurrentTimeNs();
	if (current > start)
		return current - start;
	return 0;
}

/**
 *  Obtain time left till a timestamp in the future in nanoseconds
 *
 *  @param start   starting timestamp
 *  @param timeout timeout for the event
 *  @param current timestamp to check against (pass 0 for current time)
 *
 *  @return delta or 0 (if the timeout is over)
 */
inline uint64_t getTimeLeftNs(uint64_t start, uint64_t timeout, uint64_t current = 0) {
	if (current == 0)
		current = getCurrentTimeNs();
	if (start + timeout > current)
		return start + timeout - current;
	return 0;
}

/**
 *  Convert from nanoseconds to milliseconds
 *
 *  @param t timestamp in ns
 *
 *  @return timestamp in ms
 */
constexpr  uint64_t convertNsToMs(uint64_t t) {
	return t / 1000000;
}

/**
 *  Convert from nanoseconds to seconds
 *
 *  @param t timestamp in ns
 *
 *  @return timestamp in s
 */
constexpr uint64_t convertNsToSc(uint64_t t) {
	return t / 1000000000;
}

/**
 *  Convert from milliseconds to seconds
 *
 *  @param t timestamp in ms
 *
 *  @return timestamp in s
 */
constexpr uint64_t convertMsToSc(uint64_t t) {
	return t / 1000;
}

/**
 *  Convert from milliseconds to nanoseconds
 *
 *  @param t timestamp in ms
 *
 *  @return timestamp in ns
 */
constexpr uint64_t convertMsToNs(uint64_t t) {
	return t * 1000000;
}

/**
 *  Convert from seconds to nanoseconds
 *
 *  @param t timestamp in s
 *
 *  @return timestamp in ns
 */
constexpr uint64_t convertScToNs(uint64_t t) {
	return t * 1000000000;
}

/**
 *  Convert from seconds to milliseconds
 *
 *  @param t timestamp in s
 *
 *  @return timestamp in ms
 */
constexpr uint64_t convertScToMs(uint64_t t) {
	return t * 1000;
}

#endif /* kern_time_hpp */
