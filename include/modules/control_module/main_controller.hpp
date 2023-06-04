#ifndef MAIN_CONTROLLER_HPP
#define MAIN_CONTROLLER_HPP

#include "main_controller_defines.hpp"
#include "components/GUI/screen.hpp"
#include "components/communication/main_controller_communication_interface.hpp"

namespace UVO_MainController {

class MainController{
private:
	UVO_Components::Screen m_screen;
	UVO_MainController::MainCommunicationInterface m_communication_interface{UVO_CommunicationProtocol::MAIN_CONTROLLER_ADDRESS};
public:
	MainController();
	~MainController();
	void init(void);
	void update(void);
};

}

#endif