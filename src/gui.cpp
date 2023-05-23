#include "gui.h"
#include <stdio.h>

#ifdef MAIN_CONTROLLER_MODULE
#include <iostream>

// #include "images/monke.h"
// #include "images/monke2.h"
#include "images/cool_monke.h"
#endif

namespace UVO {

GUI::GUI(void) {
	init();
}

GUI::~GUI(){

}

void GUI::init(void){
	m_tft.init();
	m_tft.setRotation(1);

	pinMode(BACKLIGHT_PIN, OUTPUT);
	digitalWrite(BACKLIGHT_PIN, HIGH);
	m_updateFrame = true;

	m_tft.setSwapBytes(true);                      // swap the byte order for pushImage() - corrects endianness
}

void GUI::update(void){
	if (m_updateFrame){
		m_updateFrame = false;
		writeFrame();
	}
}

void GUI::writeFrame(void){
	// m_tft.drawBitmap(0, 0, image, 100, 100, TFT_WHITE, TFT_BLACK);
	
	m_tft.fillScreen(TFT_BLACK);

	// m_tft.setRotation(3);
	// m_tft.fillScreen (TFT_GREEN);
	int width = 480;
	int height = 320;
	m_tft.fillScreen(TFT_BLUE);
	// m_tft.fillRect(0,0, (int) (width*0.5), (int) (height*0.9), TFT_GREEN);

	TFT_eSprite test = TFT_eSprite(&m_tft);

	// test.createSprite(100, 100);
	m_mainSprite.createSprite(160, 160);
	m_mainSprite.setSwapBytes(true);                      // swap the byte order for pushImage() - corrects endianness

	// Useful to debug
	if (m_mainSprite.created()){
		m_tft.fillRect(0,0,50,50, TFT_GREEN);
	}
	else{
		m_tft.fillRect(0,0,50,50, TFT_RED);
	}

	#ifdef MAIN_CONTROLLER_MODULE
	m_mainSprite.pushImage(-92, -33, 336, 293, cool_monke);
	m_mainSprite.pushSprite(300,100);
	#endif
}

}