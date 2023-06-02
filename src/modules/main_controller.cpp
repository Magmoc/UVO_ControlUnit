#include "modules/control_module/main_controller.hpp"

namespace UVO_MainController {
	MainController::MainController(){

	}

	MainController::~MainController(){

	}

	void MainController::init(void){
		// m_screen.init();
		m_communication_interface.init();
	}

	void MainController::update(void){
		// m_screen.update();
		m_communication_interface.update();
	}

}