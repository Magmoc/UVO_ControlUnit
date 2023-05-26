#include "module_controllers/main_controller.h"

namespace UVO {
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