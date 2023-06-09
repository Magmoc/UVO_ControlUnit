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

class MainController{
private:
	UVO_Components::s_systemState m_systemState;
	UVO_Components::s_setupSettings* m_setupSettings = &m_systemState.SetupSettings;

	Button2 m_upButton;
	Button2 m_downButton;
	Button2 m_rotaryButton;
	ESPRotary m_rotaryButton;

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

	void initButtons(void);
	void onButtonUpPress(void);
	void onButtonDownPress(void);
	void onEnterButtonPress(void);
	void onRotaryRight(void);
	void onRotaryLeft(void);

public:
	MainController();
	~MainController();
	void init(void);
	void update(void);
};

}

#endif