#include "modules/control_module/main_controller.hpp"

namespace UVO_MainController {
	MainController::MainController(){

	}

	MainController::~MainController(){

	}

	void MainController::init(void){
		#ifdef USE_SCREEN
			m_screen.init(&m_systemState.SetupSettings);
		#endif
		
		#ifdef USE_COMMUNICATION_INTERFACE
			m_communication_interface.init();
		#endif
	}

	int i = 0;

	void MainController::update(void){
		if (!m_setupSettings->isUpdated){
			delay(1000);
			m_setupSettings->addSeconds(1);
			
			m_setupSettings->isUpdated = true;

			m_screen.toggleEditSelectedElem();
		}

		#ifdef USE_SCREEN
			m_screen.update();
		#endif

		#ifdef USE_COMMUNICATION_INTERFACE
			m_communication_interface.update();
		#endif
	}

	void MainController::onButtonUpPress(void);
	void MainController::onButtonDownPress(void);
	void MainController::onEnterButtonPress(void);
	void MainController::onRotaryRight(void);
	void MainController::onRotaryLeft(void);

	void MainController::incrementSettingElement(void);
	void MainController::decrementSettingElement(void);

}