#include "gui.h"
#include <stdio.h>
#include <iostream>

Gui::Gui(void){
	init();
}

Gui::~Gui(){

}

void Gui::init(void){
	_tft.init();
	// Set the rotation to the orientation you wish to use in your project before calibration
	// (the touch coordinates returned then correspond to that rotation only)
	_tft.setRotation(1);

}

void Gui::test(void){
	// Calibrate the touch screen and retrieve the scaling factors
	//touch_calibrate();
	//   uint16_t calData[5] = { 574, 3002, 1006, 2280, 1 };
	//   _tft.setTouch(calData);

	// Clear the screen
	_tft.fillScreen(TFT_BLACK);
	// _tft.drawCentreString("",_tft.width()/2, _tft.height()/2, 2);

	_tft.fillCircle(120,180,30,TFT_WHITE);
	_tft.fillCircle(240,180,30,TFT_WHITE);
	_tft.fillCircle(360,180,30,TFT_WHITE);
}

void Gui::update(void){
	// _tft.fillCircle(120,180,30,TFT_RED);
	_tft.fillScreen(TFT_BLACK);
	_tft.fillCircle(1,1,30,TFT_RED);
	_tft.fillCircle(240,180,30,TFT_WHITE);
	_tft.fillCircle(360,180,30,TFT_WHITE);
	std::cout << "test" << std::endl;
	Serial.println("test");
}