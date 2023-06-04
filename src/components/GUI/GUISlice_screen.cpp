#include "components/GUI/GUISlice_screen.hpp"

// #include <stdio.h>
// #include <iostream>

// #include "images/monke.h"
// #include "images/monke2.h"
// #include "images/cool_monke.h"

gslc_tsElemRef* m_pElemProgress1  = NULL;
//<Save_References !End!>

// Define debug message function
static int16_t DebugOut(char ch) { if (ch == (char)'\n') Serial.println(""); else Serial.write(ch); return 0; }


namespace UVO_GUISlice {

Screen::Screen(void) {
	init();
}

Screen::~Screen(){

}

void Screen::GUISliceInit(void){
	// ------------------------------------------------
  // Initialize
  // ------------------------------------------------
  Serial.begin(9600);
  // Wait for USB Serial 
  //delay(1000);  // NOTE: Some devices require a delay after Serial.begin() before serial port can be used

  gslc_InitDebug(&DebugOut);

  // ------------------------------------------------
  // Create graphic elements
  // ------------------------------------------------
  InitGUIslice_gen();
}

void Screen::init(void){

	pinMode(BACKLIGHT_PIN, OUTPUT);
	digitalWrite(BACKLIGHT_PIN, HIGH);

	GUISliceInit();
	// m_tft.setSwapBytes(true);                      // swap the byte order for pushImage() - corrects endianness
	// m_tft.fillScreen(TFT_SKYBLUE);
}

void Screen::update(void){
	gslc_Update(&m_gui);
}

}