#include <Arduino.h>
#include <Decorator.h>


/**
 * @brief Logger (Decorator example)
 * @details A wrapper for `Serial` that also appends everything to a variable
 */


String hugeLogOfEverything = "";

class Logger : public Decorator<Print> {
	using Decorator::Decorator;
	size_t write(uint8_t c) {
		hugeLogOfEverything += (char)c;
		return pointer->write(c);
	}
};

Print* Log = new Logger(&Serial);
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
		Serial.println("\n=");
		Serial.println(hugeLogOfEverything);
		hugeLogOfEverything = "";
	}
	delay(100);
}