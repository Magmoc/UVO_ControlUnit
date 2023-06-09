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

	
	void MainController::initUI(void){
		m_upButton.begin(BUTTON_UP_PIN);
		m_downButton.begin(BUTTON_DOWN_PIN);
		m_rotaryButton.begin(ROTARY_ENCODER_PUSH_PIN);
		//TODO FIND STEPS PER INC
		m_rotaryEncoder.begin(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN);
	}
	
	void MainController::onButtonUpPress(void){
		if(!m_screen.isEditingElement()){
			m_screen.selectPreviousElem();
		}
	}
	
	void MainController::onButtonDownPress(void){
		if(!m_screen.isEditingElement()){
			m_screen.selectNextElem();
		}
	}
	
	void MainController::onEnterButtonPress(void){
		if(!m_screen.isEditingElement()){
			m_screen.beginEditSelectedElem();
		}
		else{
		}


	}
	
	void MainController::onRotaryRight(void){
		changeSettingElement(1);
	}

	void MainController::onRotaryLeft(void){
		changeSettingElement(-1);
	}

	void MainController::changeSettingElement(int t_amount){
		int16_t elem_id = m_screen.getCurrentElementID();

		// switch(elem_id)
		// {
		// case E_ELEM_SETUP_Intensity_255nm:
		// 	m_setupSettings->LED_intensity_255nm += t_amount;
		// 	break;
		// case E_ELEM_SETUP_Intensity_275nm:
		// 	m_setupSettings->LED_intensity_275nm += t_amount;
		// 	break;
		// case E_ELEM_SETUP_Intensity_285nm:
		// 	m_setupSettings->LED_intensity_285nm += t_amount;
		// 	break;
		// case E_ELEM_SETUP_Intensity_395nm:
		// 	m_setupSettings->LED_intensity_395nm += t_amount;
		// 	break;
		// case E_ELEM_SETUP_Hours:
		// 	m_setupSettings->addHours(t_amount);
		// 	break;
		// case E_ELEM_SETUP_Minutes:
		// 	m_setupSettings->addMinutes(t_amount);
		// 	break;
		// case E_ELEM_SETUP_Seconds:
		// 	m_setupSettings->addSeconds(t_amount);
		// 	break;
		// case E_ELEM_SETUP_MotorIntensity:
		// 	m_setupSettings->motor_intensity += t_amount;
		// 	break;
		// default:
		// 	break;
		// }
	}

	// void MainController::incrementSettingElement(void);
	// void MainController::decrementSettingElement(void);

}
