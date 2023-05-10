#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#include "main.h"

// #define TOUCH_CS 33

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library

//------------------------------------------------------------------------------------------

void setup() {
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(15, OUTPUT);
  digitalWrite(12, HIGH);
  // Use serial port
  Serial.begin(115200);

  // Initialise the TFT screen
  tft.init();

  // Set the rotation to the orientation you wish to use in your project before calibration
  // (the touch coordinates returned then correspond to that rotation only)
  tft.setRotation(3);

  // Calibrate the touch screen and retrieve the scaling factors
  //touch_calibrate();
  uint16_t calData[5] = { 574, 3002, 1006, 2280, 1 };
  tft.setTouch(calData);

  // Clear the screen
  tft.fillScreen(TFT_BLACK);
  tft.drawCentreString("",tft.width()/2, tft.height()/2, 2);
  
  tft.fillCircle(120,180,30,TFT_WHITE);
  tft.fillCircle(240,180,30,TFT_WHITE);
  tft.fillCircle(360,180,30,TFT_WHITE);
  digitalWrite(13, LOW);
  digitalWrite(15, LOW);
}

//------------------------------------------------------------------------------------------

void loop(void) {
  uint16_t x = 0, y = 0; // To store the touch coordinates

  // Pressed will be set true is there is a valid touch on the screen
  bool pressed = tft.getTouch(&x, &y);

  if (pressed) {
	if (x < 180) {
	  tft.fillCircle(120,180,30,TFT_RED);
	  tft.fillCircle(240,180,30,TFT_WHITE);
	  tft.fillCircle(360,180,30,TFT_WHITE);
	  digitalWrite(13, LOW);
	  digitalWrite(15, HIGH);
	}
	if (x > 180 && x < 300) {
	  tft.fillCircle(120,180,30,TFT_WHITE);
	  tft.fillCircle(240,180,30,TFT_RED);
	  tft.fillCircle(360,180,30,TFT_WHITE);
	  digitalWrite(13, HIGH);
	  digitalWrite(15, LOW);
	}
	if (x > 300) {
	  tft.fillCircle(120,180,30,TFT_WHITE);
	  tft.fillCircle(240,180,30,TFT_WHITE);
	  tft.fillCircle(360,180,30,TFT_RED);
	  digitalWrite(13, LOW);
	  digitalWrite(15, LOW);
	}
  }
}

//------------------------------------------------------------------------------------------

// Code to run a screen calibration, not needed when calibration values set in setup()
void touch_calibrate()
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  // Calibrate
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.println("Touch corners as indicated");

  tft.setTextFont(1);
  tft.println();

  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

  Serial.println(); Serial.println();
  Serial.println("// Use this calibration code in setup():");
  Serial.print("  uint16_t calData[5] = ");
  Serial.print("{ ");

  for (uint8_t i = 0; i < 5; i++)
  {
	Serial.print(calData[i]);
	if (i < 4) Serial.print(", ");
  }

  Serial.println(" };");
  Serial.print("  tft.setTouch(calData);");
  Serial.println(); Serial.println();

  tft.fillScreen(TFT_BLACK);
  
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("Calibration complete!");
  tft.println("Calibration code sent to Serial port.");
}
