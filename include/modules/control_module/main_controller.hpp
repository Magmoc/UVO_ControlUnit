#ifndef MAIN_CONTROLLER_HPP
#define MAIN_CONTROLLER_HPP

#include "main_controller_defines.hpp"

#ifdef USE_NORMAL_SCREEN
	#include "components/GUI/screen.hpp"
#else
	#include "components/GUI/GUISlice_screen.hpp"
#endif 

#include "components/settings.hpp"
#include "components/communication/main_controller_communication_interface.hpp"

namespace UVO_MainController {

class MainController{
private:
	UVO_Components::s_systemState m_systemState;
	UVO_Components::s_setupSettings* m_setupSettings = &m_systemState.SetupSettings;

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

public:
	MainController();
	~MainController();
	void init(void);
	void update(void);
};

}

#endif