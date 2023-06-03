#include "main.hpp"

void setup() {
	Serial.begin(9600);
	Controller.init();
}


void loop(void) {
	Controller.update();
}
