#include "components/GUI/GUISlice_screen.hpp"

// #include <stdio.h>
// #include <iostream>

// #include "images/monke.h"
// #include "images/monke2.h"
// #include "images/cool_monke.h"
namespace UVO_Components {
namespace GUISlice {

//TODO include logo onto screen

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
	gslc_InitDebug(&DebugOut);

	InitGUIslice_gen();
	m_screenState.init_SETUP_sel_array();
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
	m_referenceSetupSettingsPointer = t_Settings;
	displaySetupSettings(m_referenceSetupSettingsPointer);
}


void Screen::update(void){
	if (m_referenceSetupSettingsPointer->isUpdated){
		displaySetupSettings(m_referenceSetupSettingsPointer);
		m_referenceSetupSettingsPointer->isUpdated = false;
	}
		
	gslc_Update(&m_gui);
}



void Screen::displaySetupSettings(s_setupSettings* t_new){
	//TODO write this more elligible
	if (m_currentlyDisplayedSetupSettings.LED_intensity_255nm != t_new->LED_intensity_255nm){
		m_currentlyDisplayedSetupSettings.LED_intensity_255nm = t_new->LED_intensity_255nm;
		displayIntensity(m_pElem_SETUP_Intensity_255nm, m_currentlyDisplayedSetupSettings.LED_intensity_255nm);
	}

	if (m_currentlyDisplayedSetupSettings.LED_intensity_275nm != t_new->LED_intensity_275nm){
		m_currentlyDisplayedSetupSettings.LED_intensity_275nm = t_new->LED_intensity_275nm;
		displayIntensity(m_pElem_SETUP_Intensity_275nm, m_currentlyDisplayedSetupSettings.LED_intensity_275nm);
	}

	if (m_currentlyDisplayedSetupSettings.LED_intensity_285nm != t_new->LED_intensity_285nm){
		m_currentlyDisplayedSetupSettings.LED_intensity_285nm = t_new->LED_intensity_285nm;
		displayIntensity(m_pElem_SETUP_Intensity_285nm, m_currentlyDisplayedSetupSettings.LED_intensity_285nm);
	}

	if (m_currentlyDisplayedSetupSettings.LED_intensity_395nm != t_new->LED_intensity_395nm){
		m_currentlyDisplayedSetupSettings.LED_intensity_395nm = t_new->LED_intensity_395nm;
		displayIntensity(m_pElem_SETUP_Intensity_395nm, m_currentlyDisplayedSetupSettings.LED_intensity_395nm);
	}

	if (m_currentlyDisplayedSetupSettings.motor_intensity != t_new->motor_intensity){
		m_currentlyDisplayedSetupSettings.motor_intensity = t_new->motor_intensity;
		displayIntensity(m_pElem_SETUP_MotorIntensity, m_currentlyDisplayedSetupSettings.motor_intensity);
	}

	if (m_currentlyDisplayedSetupSettings.targetExposureTime != t_new->targetExposureTime){
		m_currentlyDisplayedSetupSettings.targetExposureTime = t_new->targetExposureTime;
		displayTime(m_pElem_SETUP_Hours, m_pElem_SETUP_Minutes, m_pElem_SETUP_Seconds, m_currentlyDisplayedSetupSettings.targetExposureTime);
	}

}

void Screen::displayInteger(gslc_tsElemRef* t_pElem, uint8_t t_value){
	char txt[4];
	snprintf(txt, 4, "%02d", t_value);
	gslc_ElemSetTxtStr(&m_gui, t_pElem, txt);
}

void Screen::displayIntensity(gslc_tsElemRef* t_pElem, uint8_t t_intensity){
	int intensity_percentage = uint8_to_percentage(t_intensity);
	displayInteger(t_pElem, intensity_percentage);
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


void Screen::selectPreviousElem(void){
	//TODO MAKE IT MODULO
	setSelectedElem(m_screenState.current_elem_idx - 1);
}

void Screen::selectNextElem(void){
	//TODO MAKE IT MODULO
	// int next_idx = (m_screenState.current_elem_idx + 1)
	setSelectedElem(m_screenState.current_elem_idx + 1);
}

void Screen::toggleEditSelectedElem(void){
	m_screenState.elem_is_editing = !m_screenState.elem_is_editing;

	gslc_tsElemRef* current_elem = m_screenState.getCurrentlySelectedElem();

	if (m_screenState.elem_is_editing){
		displayAsEditing(current_elem);
	}
	else {
		displayAsSelected(current_elem);
	}
}

void Screen::setSelectedElem(gslc_tsElemRef* t_pElem){
	std::optional<int> index = getIndex(m_screenState.SETUP_page_selectable_items, m_screenState.SETUP_page_selectable_items_size, t_pElem);
	
	if (!index){
		//TODO FIX WITH CUSTOM DEBUGGING FUNCTION
		throw "Element not in array";
	}

	updateSelectedElem(index.value());
}

void Screen::setSelectedElem(int t_index){
	updateSelectedElem(t_index);
}

void Screen::updateSelectedElem(int t_newSelectedIdx){
	int current_elem_idx = m_screenState.current_elem_idx;
	
	if (t_newSelectedIdx != current_elem_idx){
		gslc_tsElemRef* selectedElem = m_screenState.getCurrentlySelectedElem();
		resetElemOptions(selectedElem);
		
		m_screenState.current_elem_idx = t_newSelectedIdx;

		selectedElem = m_screenState.getCurrentlySelectedElem();
		displayAsSelected(selectedElem);
	}

}

void Screen::setColorFrame(gslc_tsElemRef* t_pElem, gslc_tsColor t_colFrame){
	gslc_tsColor current_colFill =  t_pElem->pElem->colElemFill;
	gslc_tsColor current_colFillGlow = t_pElem->pElem->colElemFillGlow;
	gslc_ElemSetCol(&m_gui, t_pElem, t_colFrame, current_colFill, current_colFillGlow);
}

void Screen::setColorFill(gslc_tsElemRef* t_pElem, gslc_tsColor t_colFill){
	gslc_tsColor current_colFrame = t_pElem->pElem->colElemFrame;
	gslc_tsColor current_colFillGlow = t_pElem->pElem->colElemFillGlow;

	gslc_ElemSetCol(&m_gui, t_pElem, current_colFrame, t_colFill, current_colFillGlow);
}

void Screen::resetElemOptions(gslc_tsElemRef* t_pElem){
	// setColorFill(t_pElem, UVO_LIGHT_BLUE);
	gslc_ElemSetFrameEn(&m_gui, t_pElem, false);
	gslc_ElemSetFillEn(&m_gui, t_pElem, false);
	gslc_ElemSetTxtCol(&m_gui, t_pElem, UVO_BLACK);
}



void Screen::displayAsSelected(gslc_tsElemRef* t_pElem){
	// setColorFill(t_pElem, UVO_WHITE);
	resetElemOptions(t_pElem);
	gslc_ElemSetFrameEn(&m_gui, t_pElem, true);
	// gslc_ElemSetFillEn(&m_gui, t_pElem, false);
}

void Screen::displayAsEditing(gslc_tsElemRef* t_pElem){
	//TODO move this to somewhere else
	//TODO remove flickering from screen
	resetElemOptions(t_pElem);

	gslc_ElemSetFrameEn(&m_gui, t_pElem, true);
	gslc_ElemSetFillEn(&m_gui, t_pElem, true);
	gslc_ElemSetTxtCol(&m_gui, t_pElem, UVO_WHITE);
}


bool Screen::hasFillEnabled(gslc_tsElemRef* t_pElem){
	return t_pElem->pElem->nFeatures & (1 << GSLC_ELEM_FEA_FILL_EN);
}


//TODO MOVE TO OTHER FILE
int Screen::uint8_to_percentage(uint8_t value){
	return value * 100.0/255;
}

//TODO MOVE TO OTHER FILE
template<typename T>
std::optional<int> Screen::getIndex(T* t_vec, int t_size, T t_elem){
	for (int i = 0; i < t_size; i++){
		if (t_vec[i] == t_elem){
			return i;
		}
	}
	
	return std::nullopt;
}

// int Screen::clip(int t_val, int t_min, int t_max){
// 		// int idx = (t_index > max_idx) ? max_idx : t_index;
// 	// idx = (idx < 0) ? 0 : idx;

// }

}
}