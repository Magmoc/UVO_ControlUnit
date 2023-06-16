#ifndef _MAIN_CONTROLLER_HPP
#define _MAIN_CONTROLLER_HPP

#include "main_controller_defines.hpp"

#ifdef USE_NORMAL_SCREEN
	#include "components/GUI/screen.hpp"
#else
	#include "components/GUI/GUISlice_screen.hpp"
#endif 

#include "components/settings.hpp"
#include "components/communication/main_controller_communication_interface.hpp"
#include "components/GUI/button.hpp"
#include "components/GUI/rotary_encoder.hpp"

namespace UVO_MainController {

#ifdef USE_BUTTONS
enum UIEvent {UIbuttonUpPressed, UIbuttonDownPressed, UIbuttonRotaryPressed, UIrotaryRight, UIrotaryLeft, UInoEvent};
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
	UVO_Components::s_setupSettings m_setupSettings;

	#ifdef USE_BUTTONS
	Button2 m_upButton;
	Button2 m_downButton;
	Button2 m_rotaryButton;
	ESPRotary m_rotaryEncoder;
	#endif

	#ifdef USE_SCREEN
	#ifdef USE_NORMAL_SCREEN
		#error "THE USE OF THE NORMAL SCREEN IS CURRENTLY NOT IMPLEMENTED, PLEASE USE THE GUISLICE CODE" 
		UVO_Components::Screen::Screen m_screen;
	#else
		UVO_Components::GUISlice::Screen m_screen;
	#endif
	#endif

	#ifdef USE_COMMUNICATION_INTERFACE
		UVO_MainController::MainCommunicationInterface m_communication_interface{UVO_CommunicationProtocol::MAIN_CONTROLLER_ADDRESS};
	#endif

	#ifdef USE_BUTTONS
	void initUI(void);
	void processUI(void);

	void onButtonUpPress(Button2& t_button);
	void onButtonDownPress(Button2& t_button);
	void onEnterButtonPress(Button2& t_button);
	void onRotaryRight(ESPRotary& t_rotary);
	void onRotaryLeft(ESPRotary& t_rotary);
	void changeSettingElement(int t_amount);
	#endif

public:
	MainController();
	~MainController();
	void init(void);
	void update(void);
};

}

#endif