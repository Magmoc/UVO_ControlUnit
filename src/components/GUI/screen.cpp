// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#include "components/GUI/screen.hpp"

// #include <stdio.h>
// #include <iostream>

namespace UVO_Components {
namespace Screen {

Screen::Screen(void) {
	init();
}

Screen::~Screen(){

}

void Screen::init(void){
	m_tft.init();
	m_tft.setRotation(1);

	pinMode(BACKLIGHT_PIN, OUTPUT);
	digitalWrite(BACKLIGHT_PIN, HIGH);

	m_tft.setSwapBytes(true);                      // swap the byte order for pushImage() - corrects endianness
	m_tft.fillScreen(TFT_SKYBLUE);
	m_updateFrame = true;
}

void Screen::update(void){
	if (m_updateFrame){
		m_updateFrame = false;
		test();
	}
}


void Screen::test(void){
	m_tft.fillScreen(UVO_DARK_BLUE);

	m_screen.createSprite(m_SPRITE_WIDTH, m_SPRITE_HEIGHT);	
	m_screen.fillScreen(TFT_TRANSPARENT);

	m_screen.fillRect(0, 0, 300, 100, TFT_GREEN);

	setBackground(m_screen);
	
	m_screen.setCursor(100, 300);
	m_screen.setTextColor(TFT_BLACK, TFT_TRANSPARENT);
	m_screen.setTextSize(3);
	m_screen.println("Hello\n");
	
	m_screen.pushSprite(0,0, TFT_TRANSPARENT);
	m_screen.deleteSprite();
}

void Screen::setBackground(TFT_eSprite& sprite){
	sprite.fillCircle(m_TFT_WIDTH/3, m_TFT_HEIGHT/2, 40, TFT_GREENYELLOW);
	sprite.fillCircle(m_TFT_WIDTH/3, m_TFT_HEIGHT/2, 40, TFT_GREENYELLOW);
}

void Screen::setBackgroundText(TFT_eSPI& sprite){
	sprite.setTextColor(TFT_BLACK);
	sprite.setTextSize(3);

	sprite.setCursor(20, 30);
	sprite.println("Intensity (255nm):");
	
	sprite.setCursor(20, 60);
	sprite.println("Intensity (275nm):");
	
	sprite.setCursor(20, 90);
	sprite.println("Intensity (285nm):");
	
	sprite.setCursor(20, 120);
	sprite.println("Intensity (395nm):");
}

void Screen::writeFrame(void){
	// m_tft.drawBitmap(0, 0, image, 100, 100, TFT_WHITE, TFT_BLACK);
	
	m_tft.fillScreen(TFT_BLACK);

	// m_tft.setRotation(3);
	// m_tft.fillScreen (TFT_GREEN);
	m_tft.fillScreen(TFT_BLUE);
	// m_tft.fillRect(0,0, (int) (width*0.5), (int) (height*0.9), TFT_GREEN);

	TFT_eSprite test = TFT_eSprite(&m_tft);

	// test.createSprite(100, 100);
	m_screen.createSprite(160, 160);
	m_screen.setSwapBytes(true);                      // swap the byte order for pushImage() - corrects endianness

	// Useful to debug
	if (m_screen.created()){
		m_tft.fillRect(0,0,50,50, TFT_GREEN);
	}
	else{
		m_tft.fillRect(0,0,50,50, TFT_RED);
	}

	// m_screen.pushSprite(300,100);
}

}
}