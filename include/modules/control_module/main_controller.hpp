#ifndef MAIN_CONTROLLER_HPP
#define MAIN_CONTROLLER_HPP

#include "main_controller_defines.hpp"

#ifdef USE_GUISLICE_SCREEN
	#include "components/GUI/GUISlice_screen.hpp"
#else
	#include "components/GUI/screen.hpp"
#endif 

#include "components/communication/main_controller_communication_interface.hpp"

namespace UVO_MainController {

class MainController{
private:
	#ifdef USE_GUISLICE_SCREEN
		UVO_GUISlice::Screen m_screen;
	#else
		UVO_Components::Screen m_screen;
	#endif


	UVO_MainController::MainCommunicationInterface m_communication_interface{UVO_CommunicationProtocol::MAIN_CONTROLLER_ADDRESS};
public:
	MainController();
	~MainController();
	void init(void);
	void update(void);
};

}

#endif