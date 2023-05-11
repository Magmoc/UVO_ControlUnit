#include "gui.h"
#include <stdio.h>
#include <iostream>

GUI::GUI(void){
	init();
}

GUI::~GUI(){

}

void GUI::init(void){
	_tft.init();
	// Set the rotation to the orientation you wish to use in your project before calibration
	// (the touch coordinates returned then correspond to that rotation only)
	_tft.setRotation(1);
	pinMode(BACKLIGHT_PIN, OUTPUT);
	digitalWrite(BACKLIGHT_PIN, HIGH);
	update_frame = true;
}

void GUI::update(void){
	if (update_frame){
		write_frame();
	}
}

void GUI::write_frame(void){
	update_frame = false;
	_tft.fillScreen(TFT_GREEN);

}