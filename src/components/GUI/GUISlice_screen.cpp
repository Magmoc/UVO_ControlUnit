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
	m_setupSettingsPointer = t_Settings;
}

#ifdef DEBUG_MODE
int i = 0;
#endif

void Screen::update(void){
	// delay(10);
	if (m_setupSettingsPointer->isUpdated){

		#ifdef DEBUG_MODE
		//TODO Make a function for debugging
		char txt[4] = {};
		snprintf(txt, 4, "%02d", i++);
		gslc_ElemSetTxtStr(&m_gui, m_pElem_SETUP_Dosis_255nm, txt);
		#endif

		displaySetupSettings();


		displaySelected(m_pElem_SETUP_Intensity_285nm);


		gslc_Update(&m_gui);
		m_setupSettingsPointer->isUpdated = false;
	}
}

void Screen::displaySelected(gslc_tsElemRef* t_pElem){
	gslc_tsColor current_colFrame = t_pElem->pElem->colElemFrame;
	gslc_tsColor current_colFill = t_pElem->pElem->colElemFill;
	gslc_tsColor current_colFillGlow = t_pElem->pElem->colElemFillGlow;

	gslc_ElemSetCol(&m_gui, t_pElem, current_colFrame, UVO_WHITE, current_colFillGlow);
	gslc_ElemSetFrameEn(&m_gui, t_pElem, true);
	gslc_ElemSetFillEn(&m_gui, t_pElem, true);
}

void Screen::displaySetupSettings(void){
	displayIntensity(m_pElem_SETUP_Intensity_255nm, m_setupSettingsPointer->LED_intensity_255nm);
	displayIntensity(m_pElem_SETUP_Intensity_275nm, m_setupSettingsPointer->LED_intensity_275nm);
	displayIntensity(m_pElem_SETUP_Intensity_285nm, m_setupSettingsPointer->LED_intensity_285nm);
	displayIntensity(m_pElem_SETUP_Intensity_395nm, m_setupSettingsPointer->LED_intensity_395nm);
	
	displayIntensity(m_pElem_SETUP_MotorIntensity, m_setupSettingsPointer->motor_intensity);

	displayTime(m_pElem_SETUP_Hours, m_pElem_SETUP_Minutes, m_pElem_SETUP_Seconds, m_setupSettingsPointer->targetExposureTime);
}

void Screen::displayIntensity(gslc_tsElemRef* t_pElem, uint8_t t_intensity){
	int intensity_percentage = uint8_to_percentage(t_intensity);
	
	char txt[4];
	snprintf(txt, 4, "%02d", intensity_percentage);
	gslc_ElemSetTxtStr(&m_gui, t_pElem, txt);
}

void Screen::displayTime(gslc_tsElemRef* t_pElem_hour, gslc_tsElemRef* t_pElem_minutes, gslc_tsElemRef* t_pElem_seconds, time_t t_displayTime){
	char hours_txt[3] = {0};
	char minutes_txt[3] = {0};
	char seconds_txt[3] = {0};
	tm* curr_tm = localtime(&t_displayTime);
	strftime(hours_txt, sizeof(hours_txt), "%HH", curr_tm);
	strftime(minutes_txt, sizeof(minutes_txt), "%MM", curr_tm);
	strftime(seconds_txt, sizeof(seconds_txt), "%SS", curr_tm);

	gslc_ElemSetTxtStr(&m_gui, t_pElem_hour, hours_txt);
	gslc_ElemSetTxtStr(&m_gui, t_pElem_minutes, minutes_txt);
	gslc_ElemSetTxtStr(&m_gui, t_pElem_seconds, seconds_txt);
}

int Screen::uint8_to_percentage(uint8_t value){
	return value * 100.0/255;
}

}
}