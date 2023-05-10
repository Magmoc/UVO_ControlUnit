#include <SPI.h>
#include "main.h"


Gui Screen;

#define BACKLIGHT_PIN 12

void setup() {
	// Use serial port
	Serial.begin(9600);
	// Screen.test();
	pinMode(BACKLIGHT_PIN, OUTPUT);
	// pinMode(33, OUTPUT);
	// pinMode(13, OUTPUT);
	// pinMode(15, OUTPUT);
	// pinMode(CS, OUTPUT);
	// pinMode(2, OUTPUT);

	digitalWrite(BACKLIGHT_PIN, HIGH);
	// delay(1000);
	// digitalWrite(BACKLIGHT_PIN, LOW);
	// digitalWrite(CS, HIGH);
	// digitalWrite(33, LOW);
	// digitalWrite(2, HIGH);
	// Screen.test();

	Screen.init();
	Screen.update();
}

//------------------------------------------------------------------------------------------

void loop(void) {
	// Screen._tft.fillScreen(TFT_GREEN);

	// Serial.println("test");
	// Screen.update();
	// digitalWrite(13, LOW);
	// digitalWrite(15, HIGH);
}
