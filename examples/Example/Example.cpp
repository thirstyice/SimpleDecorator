#include <Arduino.h>
#include <Decorator.h>


/**
 * @brief Logger (Decorator example)
 * @details A wrapper for `Serial` that also appends everything to a variable
 * 
 * @note You will probably run out of ram very fast if you actually do this
 */


String hugeLogOfEverything = "";

class Logger : public Decorator<Print> {
	using Decorator::Decorator;
	size_t write(uint8_t c) {
		hugeLogOfEverything += c;
		return pointer->write(c);
	}
};

Logger Log(&Serial);
char c = 32; // (' ')

void setup() {
	Serial.begin(9600);
}


// Log the characters from ' ' to '~'
void loop() {
	Log->print((char)c);
	c++;
	if (c>=127) {
		c=32;
	}
	delay(500);
}