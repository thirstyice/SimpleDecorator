#include <Arduino.h>
#include <Decorator.h>


/**
 * @brief Logger (Decorator example)
 * @details A wrapper for `Serial` that also appends everything to a variable
 * 
 * @note You will probably run out of ram very fast if you actually do this
 */


String hugeLogOfEverything = "";

class Logger : Decorator<HardwareSerial> {
	using Decorator::Decorator;
	size_t write(char c) {
		hugeLogOfEverything += c;
		return pointer->write(c);
	}
	size_t write(const char* str, size_t length) {
		String input = "";
		if (input.reserve(length+1)) {
			strlcpy(input.begin(), str, length);
		}
		hugeLogOfEverything += input;
		return pointer->write(str, length);
	}
};

Logger Log(Serial);