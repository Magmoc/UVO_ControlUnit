// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#ifndef _MAIN_CONTROLLER_HPP
#define _MAIN_CONTROLLER_HPP

#include "main_controller_defines.hpp"

#ifdef USE_SCREEN
#ifdef USE_NORMAL_SCREEN
	#include "components/GUI/screen.hpp"
#else
	#include "components/GUI/GUISlice_screen.hpp"
#endif 
#endif

#include "components/settings.hpp"
#include "components/communication/main_controller_communication_interface.hpp"
#include "components/GUI/button.hpp"
#include "components/GUI/rotary_encoder.hpp"

namespace UVO_MainController {

#ifdef USE_BUTTONS
enum UIEvent {UInoEvent, UIbuttonUpPressed, UIbuttonDownPressed, UIbuttonRotaryPressed, UIrotaryRight, UIrotaryLeft, UIbusy};
extern volatile UIEvent last_ui_event;

void onButtonUpPressISR(Button2& t_button);
void onButtonDownPressISR(Button2& t_button);
void onButtonRotaryPressISR(Button2& t_button);
void onRotaryRightISR(ESPRotary& t_rotary);
void onRotaryLeftISR(ESPRotary& t_rotary);
#endif


class MainController{
private:
	UVO_Components::s_systemState m_systemState;
	UVO_Components::s_setupSettings* m_setupSettings = &(m_systemState.SetupSettings);

	#ifdef USE_SCREEN
	#ifdef USE_NORMAL_SCREEN
		#error "THE USE OF THE NORMAL SCREEN IS CURRENTLY NOT IMPLEMENTED, PLEASE USE THE GUISLICE CODE" 
		UVO_Components::Screen::Screen m_screen;
	#else
		UVO_Components::GUISlice::Screen m_screen;
	#endif
	#endif

	#ifdef USE_COMMUNICATION_INTERFACE
	UVO_MainController::MainCommunicationInterface m_communication_interface;
	#endif
	
	void sendSetupSettings(void);

	void setSystemState(UVO_Components::e_systemState t_state);

	#ifdef USE_BUTTONS
	Button2 m_upButton;
	Button2 m_downButton;
	Button2 m_rotaryButton;
	ESPRotary m_rotaryEncoder;

	void initUI(void);
	void processUI(void);
	
	void changeSettingElement(int t_amount);

	void onButtonUpPress(Button2& t_button);
	void onButtonDownPress(Button2& t_button);
	void onRotaryButtonPress(Button2& t_button);
	void onRotaryRight(ESPRotary& t_rotary);
	void onRotaryLeft(ESPRotary& t_rotary);

	void onButtonUpPress_setup(Button2& t_button);
	void onButtonDownPress_setup(Button2& t_button);
	void onRotaryButtonPress_setup(Button2& t_button);
	void onRotaryRight_setup(ESPRotary& t_rotary);
	void onRotaryLeft_setup(ESPRotary& t_rotary);

	void onButtonUpPress_monitor(Button2& t_button);
	void onButtonDownPress_monitor(Button2& t_button);
	void onRotaryButtonPress_monitor(Button2& t_button);
	void onRotaryRight_monitor(ESPRotary& t_rotary);
	void onRotaryLeft_monitor(ESPRotary& t_rotary);
	#endif

public:
	MainController();
	~MainController();
	void init(void);
	void update(void);
};

}

#endif