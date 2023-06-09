#include "modules/control_module/main_controller.hpp"

namespace UVO_MainController {
	volatile UIEvent last_ui_event = UInoEvent;

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

		initUI();
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

		if (last_ui_event != UInoEvent){
			processUI();
		}
	}

	
	void MainController::initUI(void){
		m_upButton.begin(BUTTON_UP_PIN, 5U, false);
		m_downButton.begin(BUTTON_DOWN_PIN, 5U, false);
		m_rotaryButton.begin(ROTARY_ENCODER_PUSH_PIN, 5U, false);
		//TODO FIND STEPS PER INC
		m_rotaryEncoder.begin(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN);

		m_upButton.setClickHandler(onButtonUpPressISR);
		m_downButton.setClickHandler(onButtonDownPressISR);
		m_rotaryButton.setClickHandler(onButtonRotaryPressISR);

		m_rotaryEncoder.setRightRotationHandler(onRotaryRightISR);
		m_rotaryEncoder.setLeftRotationHandler(onRotaryLeftISR);
	}
	
	void MainController::processUI(void){
		switch (last_ui_event){
		case UIbuttonUpPressed:
			onButtonUpPress(m_upButton);
			break;
		case UIbuttonDownPressed:
			onButtonDownPress(m_downButton);
			break;
		case UIbuttonRotaryPressed:
			onButtonRotaryPressISR(m_rotaryButton);
			break;
		case UIrotaryLeft:
			onRotaryLeft(m_rotaryEncoder);
			break;
		case UIrotaryRight:
			onRotaryRight(m_rotaryEncoder);
			break;
		
		default:
			break;
		}

		last_ui_event = UInoEvent;
	}

	void onButtonUpPressISR(Button2& t_button){
		last_ui_event=UIbuttonUpPressed;
	}
	void onButtonDownPressISR(Button2& t_button){
		last_ui_event=UIbuttonDownPressed;
	}
	void onButtonRotaryPressISR(Button2& t_button){
		last_ui_event=UIbuttonRotaryPressed;
	}
	void onRotaryRightISR(ESPRotary& t_rotary){
		last_ui_event=UIrotaryRight;
	}
	void onRotaryLeftISR(ESPRotary& t_rotary){
		last_ui_event=UIrotaryLeft;
	}

	void MainController::onButtonUpPress(Button2& t_button){
		if(!m_screen.isEditingElement()){
			m_screen.selectPreviousElem();
		}
	}
	
	void MainController::onButtonDownPress(Button2& t_button){
		if(!m_screen.isEditingElement()){
			m_screen.selectNextElem();
		}
	}
	
	void MainController::onEnterButtonPress(Button2& t_button){
		if(!m_screen.isEditingElement()){
			m_screen.beginEditSelectedElem();
		}
		else{

		}


	}
	
	void MainController::onRotaryRight(ESPRotary& t_rotary){
		if(m_screen.isEditingElement()){
			changeSettingElement(1);
		}
		else{
			m_screen.selectNextElem();
		}
	}

	void MainController::onRotaryLeft(ESPRotary& t_rotary){
		if(m_screen.isEditingElement()){
			changeSettingElement(-1);
		}
		else{
			m_screen.selectPreviousElem();
		}
	
	}


	void MainController::changeSettingElement(int t_amount){
		int16_t elem_id = m_screen.getCurrentElementID();

		switch(elem_id)
		{
		case UVO_Components::GUISlice::E_ELEM_SETUP_Intensity_255nm:
			m_setupSettings->LED_intensity_255nm += t_amount;
			break;
		case UVO_Components::GUISlice::E_ELEM_SETUP_Intensity_275nm:
			m_setupSettings->LED_intensity_275nm += t_amount;
			break;
		case UVO_Components::GUISlice::E_ELEM_SETUP_Intensity_285nm:
			m_setupSettings->LED_intensity_285nm += t_amount;
			break;
		case UVO_Components::GUISlice::E_ELEM_SETUP_Intensity_395nm:
			m_setupSettings->LED_intensity_395nm += t_amount;
			break;
		case UVO_Components::GUISlice::E_ELEM_SETUP_Hours:
			m_setupSettings->addHours(t_amount);
			break;
		case UVO_Components::GUISlice::E_ELEM_SETUP_Minutes:
			m_setupSettings->addMinutes(t_amount);
			break;
		case UVO_Components::GUISlice::E_ELEM_SETUP_Seconds:
			m_setupSettings->addSeconds(t_amount);
			break;
		case UVO_Components::GUISlice::E_ELEM_SETUP_MotorIntensity:
			m_setupSettings->motor_intensity += t_amount;
			break;
		default:
			break;
		}
	}

}
