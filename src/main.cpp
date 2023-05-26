#include "main.h"


void setup() {
	Serial.begin(9600);
	Controller.init();
}

void loop(void) {
	Controller.update();
	// Screen.m_tft.fillScreen(TFT_GREEN);

	// Serial.println("test");
	// Screen.update();
	// digitalWrite(13, LOW);
	// digitalWrite(15, HIGH);
}
