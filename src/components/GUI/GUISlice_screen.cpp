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
		displaySetupSettings();

		gslc_Update(&m_gui);
		m_setupSettings->isUpdated = false;
	}
}

void Screen::displaySetupSettings(void){
	displayIntensity(m_pElem_SETUP_Intensity_255nm, m_setupSettings->LED_intensity_255nm);
	displayIntensity(m_pElem_SETUP_Intensity_275nm, m_setupSettings->LED_intensity_275nm);
	displayIntensity(m_pElem_SETUP_Intensity_285nm, m_setupSettings->LED_intensity_285nm);
	displayIntensity(m_pElem_SETUP_Intensity_395nm, m_setupSettings->LED_intensity_395nm);
	
	displayIntensity(m_pElem_SETUP_MotorIntensity, m_setupSettings->motor_intensity);

	displayTime(m_pElem_SETUP_Hours, m_pElem_SETUP_Minutes, m_pElem_SETUP_Seconds, m_setupSettings->targetExposureTime);
}

void Screen::displayIntensity(gslc_tsElemRef* t_elem, uint8_t t_intensity){
	int intensity_percentage = uint8_to_percentage(t_intensity);
	
	char txt[4];
	snprintf(txt, 4, "%02d", intensity_percentage);
	gslc_ElemSetTxtStr(&m_gui, t_elem, txt);
}

void Screen::displayTime(gslc_tsElemRef* t_hour, gslc_tsElemRef* t_minutes, gslc_tsElemRef* t_seconds, time_t t_displayTime){
	char hours_txt[3] = {0};
	char minutes_txt[3] = {0};
	char seconds_txt[3] = {0};
	tm* curr_tm = localtime(&t_displayTime);
	strftime(hours_txt, sizeof(hours_txt), "%HH", curr_tm);
	strftime(minutes_txt, sizeof(minutes_txt), "%MM", curr_tm);
	strftime(seconds_txt, sizeof(seconds_txt), "%SS", curr_tm);

	gslc_ElemSetTxtStr(&m_gui, t_hour, hours_txt);
	gslc_ElemSetTxtStr(&m_gui, t_minutes, minutes_txt);
	gslc_ElemSetTxtStr(&m_gui, t_seconds, seconds_txt);
}

int Screen::uint8_to_percentage(uint8_t value){
	return value * 100.0/255;
}

}
}