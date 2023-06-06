#include "modules/control_module/main_controller.hpp"

namespace UVO_MainController {
	MainController::MainController(){

	}

	MainController::~MainController(){

	}

	void MainController::init(void){
		#ifdef USE_SCREEN
			m_screen.init(&m_setupSettings);
		#endif
		
		#ifdef USE_COMMUNICATION_INTERFACE
			m_communication_interface.init();
		#endif
	}

	void MainController::update(void){
		if (!m_setupSettings.isUpdated){
			delay(1000);
			m_setupSettings.addSeconds(1);
			m_setupSettings.isUpdated = true;
		}

		#ifdef USE_SCREEN
			m_screen.update();
		#endif

		#ifdef USE_COMMUNICATION_INTERFACE
			m_communication_interface.update();
		#endif
	}

}