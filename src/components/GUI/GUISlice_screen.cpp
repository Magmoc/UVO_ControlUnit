#include "components/GUI/GUISlice_screen.hpp"

// #include <stdio.h>
// #include <iostream>

// #include "images/monke.h"
// #include "images/monke2.h"
// #include "images/cool_monke.h"
namespace UVO_Components {
namespace GUISlice {

//TODO include image

#include "components/GUI/GUISlice_references_content.hpp"

Screen::Screen(s_setupSettings* t_initSettings){
	init(t_initSettings);
}

Screen::Screen(void){
	init();
}

Screen::~Screen(){

}

void Screen::GUISliceInit(void){
  Serial.begin(9600);

  gslc_InitDebug(&DebugOut);

  InitGUIslice_gen();
}

void Screen::init(void){
	pinMode(BACKLIGHT_PIN, OUTPUT);
	digitalWrite(BACKLIGHT_PIN, HIGH);

	GUISliceInit();
	gslc_Update(&m_gui);
}

void Screen::init(s_setupSettings* t_initSettings){
	setSetupSettings(t_initSettings);
	init();
}

void Screen::setSetupSettings(s_setupSettings* t_Settings){
	m_setupSettings = t_Settings;
}


void Screen::update(void){
	// delay(10);
	if (m_setupSettings->isUpdated){
		m_setupSettings->isUpdated = false;
		displaySetupSettings();

		gslc_Update(&m_gui);
	}
}

void Screen::displaySetupSettings(void){
	displayIntensity(m_pElem_SETUP_Intensity_255nm, m_setupSettings->LED_intensity_255nm);
	displayIntensity(m_pElem_SETUP_Intensity_275nm, m_setupSettings->LED_intensity_275nm);
	displayIntensity(m_pElem_SETUP_Intensity_285nm, m_setupSettings->LED_intensity_285nm);
	displayIntensity(m_pElem_SETUP_Intensity_395nm, m_setupSettings->LED_intensity_395nm);
	
	displayIntensity(m_pElem_SETUP_MotorIntensity, m_setupSettings->motor_intensity);
}

void Screen::displayIntensity(gslc_tsElemRef* elem, uint8_t intensity){
	int intensity_percentage = uint8_to_percentage(intensity);
	
	char txt[4];
	snprintf(txt, 4, "%02d", intensity_percentage);
	gslc_ElemSetTxtStr(&m_gui, elem, txt);
}

int Screen::uint8_to_percentage(uint8_t value){
	return value * 100.0/255;
}

}
}