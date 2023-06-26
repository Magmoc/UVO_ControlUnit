// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#include "main.hpp"

// #include <Wire.h>
// #include <Arduino.h>

// #include "modules/control_module/main_controller_defines.hpp"

void setup() {
	// Serial.begin(9600);
	Controller.init();
	// Wire.setPins(SDA_PIN, SCL_PIN);
	// Wire.begin(80);
}


void loop(void) {
	// delay(100);
	// Wire.beginTransmission(10);
	// Wire.printf("Hello World!");
	// Wire.endTransmission();
	Controller.update();
}
