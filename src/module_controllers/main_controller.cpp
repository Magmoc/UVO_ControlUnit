#include "module_controllers/main_controller.hpp"

namespace UVO_MainController {
	MainController::MainController(){

	}

	MainController::~MainController(){

	}

	void MainController::init(void){
		m_screen.init();
	}

	void MainController::update(void){
		m_screen.update();
	}

}