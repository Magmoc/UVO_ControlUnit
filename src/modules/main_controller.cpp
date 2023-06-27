// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
//
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#include "modules/control_module/main_controller.hpp"

namespace UVO_MainController
{
#ifdef USE_BUTTONS
	volatile UIEvent last_ui_event = UInoEvent;
#endif

	MainController::MainController(){
	
	}

	MainController::~MainController(){
	
	}

	void MainController::init(void){
		#ifdef USE_SCREEN
		m_screen.init(m_setupSettings);
		#endif

		#ifdef USE_COMMUNICATION_INTERFACE
		m_communication_interface.init();
		#endif

		#ifdef USE_BUTTONS
		initUI();
		#endif
	}


	void MainController::update(void)
	{	

		#ifdef USE_BUTTONS
		m_rotaryButton.loop();
		m_upButton.loop();
		m_downButton.loop();
		m_rotaryEncoder.loop();
		
		// TODO UIbusy incase of threading if it were to be implemented
		if (last_ui_event != UInoEvent && last_ui_event != UIbusy)
		{
			processUI();
		}
		#endif

		#ifdef USE_SCREEN
		m_screen.update();
		#endif

		#ifdef USE_COMMUNICATION_INTERFACE
		m_communication_interface.update();
		#endif
	}

	// TODO Rethink layout of system states and pages
	//      because this is not scalable to do it for every page and switch statement
	void MainController::setSystemState(UVO_Components::e_systemState t_state)
	{
		m_systemState.state = t_state;


		switch (t_state)
		{
		case UVO_Components::e_systemState::Setup:
			#ifdef USE_SCREEN
			m_screen.selectSetupPage();
			#endif
			break;
		case UVO_Components::e_systemState::Monitor:
			#ifdef USE_SCREEN
			m_screen.selectMonitorPage();
			#endif

			break;
		default:
			break;
		}
	}

#ifdef USE_COMMUNICATION_INTERFACE
	void MainController::sendSetupSettings(void){		
		// //TOP LED DRIVER
		// m_communication_interface.setPWMDutyCycle(	UVO_CommunicationProtocol::drivers::TOP_LEDDriver::pwm_driver_255nm, 
		// 											m_setupSettings->LED_intensity_255nm);
		// m_communication_interface.setPWMDutyCycle(	UVO_CommunicationProtocol::drivers::TOP_LEDDriver::pwm_driver_275nm, 
		// 											m_setupSettings->LED_intensity_275nm);
		// m_communication_interface.setPWMDutyCycle(	UVO_CommunicationProtocol::drivers::TOP_LEDDriver::pwm_driver_285nm, 
		// 											m_setupSettings->LED_intensity_285nm);
		// m_communication_interface.setPWMDutyCycle(	UVO_CommunicationProtocol::drivers::TOP_LEDDriver::pwm_driver_395nm, 
		// 											m_setupSettings->LED_intensity_395nm);

		// //BOTOM LED DRIVER											
		// m_communication_interface.setPWMDutyCycle(	UVO_CommunicationProtocol::drivers::BOTTOM_LEDDriver::pwm_driver_255nm, 
		// 											m_setupSettings->LED_intensity_255nm);
		// m_communication_interface.setPWMDutyCycle(	UVO_CommunicationProtocol::drivers::BOTTOM_LEDDriver::pwm_driver_275nm, 
		// 											m_setupSettings->LED_intensity_275nm);
		// m_communication_interface.setPWMDutyCycle(	UVO_CommunicationProtocol::drivers::BOTTOM_LEDDriver::pwm_driver_285nm, 
		// 											m_setupSettings->LED_intensity_285nm);
		// m_communication_interface.setPWMDutyCycle(	UVO_CommunicationProtocol::drivers::BOTTOM_LEDDriver::pwm_driver_395nm, 
		// 											m_setupSettings->LED_intensity_395nm);
		
		//MOTOR CONTROLLER
		m_communication_interface.setPWMDutyCycle(	UVO_CommunicationProtocol::drivers::motor_controller::pwm_driver_motor, 
													m_setupSettings->motor_intensity);
	}
#else
	void MainController::sendSetupSettings(void){}
#endif

#ifdef USE_BUTTONS
	void MainController::initUI(void)
	{
		pinMode(BUTTON_UP_PIN, INPUT);
		pinMode(BUTTON_DOWN_PIN, INPUT);
		pinMode(ROTARY_ENCODER_A_PIN, INPUT);
		pinMode(ROTARY_ENCODER_B_PIN, INPUT);
		pinMode(ROTARY_ENCODER_PUSH_PIN, INPUT);

		m_upButton.begin(BUTTON_UP_PIN, INPUT, false);
		m_downButton.begin(BUTTON_DOWN_PIN, INPUT, false);
		m_rotaryButton.begin(ROTARY_ENCODER_PUSH_PIN, INPUT, false);

		int ROTARY_CLICKS_PER_STEP = 5U;
		m_rotaryEncoder.begin(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_CLICKS_PER_STEP);

		m_upButton.setPressedHandler(onButtonUpPressISR);
		m_downButton.setPressedHandler(onButtonDownPressISR);
		m_rotaryButton.setPressedHandler(onButtonRotaryPressISR);

		m_rotaryEncoder.setRightRotationHandler(onRotaryRightISR);
		m_rotaryEncoder.setLeftRotationHandler(onRotaryLeftISR);
	}

	void MainController::changeSettingElement(int t_amount)
	{
		int16_t elem_id = m_screen.getCurrentElementID();

		switch (elem_id)
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

		m_setupSettings->isUpdated = true;
	}

	void MainController::processUI(void)
	{
		switch (last_ui_event)
		{
		case UIbuttonUpPressed:
			last_ui_event = UIbusy;
			onButtonUpPress(m_upButton);
			break;
		case UIbuttonDownPressed:
			last_ui_event = UIbusy;
			onButtonDownPress(m_downButton);
			break;
		case UIbuttonRotaryPressed:
			last_ui_event = UIbusy;
			onRotaryButtonPress(m_rotaryButton);
			break;
		case UIrotaryLeft:
			last_ui_event = UIbusy;
			onRotaryLeft(m_rotaryEncoder);
			break;
		case UIrotaryRight:
			last_ui_event = UIbusy;
			onRotaryRight(m_rotaryEncoder);
			break;

		case UInoEvent:
		default:
			break;
		}

		last_ui_event = UInoEvent;
	}

	// *****************************************************
	//
	// 					UI	ISR
	//
	// *****************************************************

	// Use ISR so that you dont do too much during interrupts
	void onButtonUpPressISR(Button2 &t_button)
	{
		if (last_ui_event == UInoEvent)
		{
			last_ui_event = UIbuttonUpPressed;
		}
	}
	void onButtonDownPressISR(Button2 &t_button)
	{
		if (last_ui_event == UInoEvent)
		{
			last_ui_event = UIbuttonDownPressed;
		}
	}
	void onButtonRotaryPressISR(Button2 &t_button)
	{
		if (last_ui_event == UInoEvent)
		{
			last_ui_event = UIbuttonRotaryPressed;
		}
	}
	void onRotaryRightISR(ESPRotary &t_rotary)
	{
		if (last_ui_event == UInoEvent)
		{
			last_ui_event = UIrotaryRight;
		}
	}
	void onRotaryLeftISR(ESPRotary &t_rotary)
	{
		if (last_ui_event == UInoEvent)
		{
			last_ui_event = UIrotaryLeft;
		}
	}

	// *****************************************************
	//
	// 				TOPLEVEL UI HANDLING
	//
	// *****************************************************
	void MainController::onButtonUpPress(Button2 &t_button)
	{
		switch (m_systemState.state)
		{
		case UVO_Components::e_systemState::Setup:
			onButtonUpPress_setup(t_button);
			break;
		case UVO_Components::e_systemState::Monitor:
			onButtonUpPress_monitor(t_button);
			break;
		default:
			break;
		}
	}

	void MainController::onButtonDownPress(Button2 &t_button)
	{
		switch (m_systemState.state)
		{
		case UVO_Components::e_systemState::Setup:
			onButtonDownPress_setup(t_button);
			break;
		case UVO_Components::e_systemState::Monitor:
			onButtonDownPress_monitor(t_button);
			break;
		default:
			break;
		}
	}

	void MainController::onRotaryButtonPress(Button2 &t_button)
	{
		switch (m_systemState.state)
		{
		case UVO_Components::e_systemState::Setup:
			onRotaryButtonPress_setup(t_button);
			break;
		case UVO_Components::e_systemState::Monitor:
			onRotaryButtonPress_monitor(t_button);
			break;
		default:
			break;
		}
	}

	void MainController::onRotaryRight(ESPRotary &t_rotary)
	{
		switch (m_systemState.state)
		{
		case UVO_Components::e_systemState::Setup:
			onRotaryRight_setup(t_rotary);
			break;
		case UVO_Components::e_systemState::Monitor:
			onRotaryRight_monitor(t_rotary);
			break;
		default:
			break;
		}
	}

	void MainController::onRotaryLeft(ESPRotary &t_rotary)
	{
		switch (m_systemState.state)
		{
		case UVO_Components::e_systemState::Setup:
			onRotaryLeft_setup(t_rotary);
			break;
		case UVO_Components::e_systemState::Monitor:
			onRotaryLeft_monitor(t_rotary);
			break;
		default:
			break;
		}
	}

	// *****************************************************
	//
	// 				UI HANDLING SETUP SCREEN
	//
	// *****************************************************
	void MainController::onButtonUpPress_setup(Button2 &t_button)
	{
		if (!m_screen.isEditingElement())
		{
			m_screen.selectPreviousElem();
		}
	}

	void MainController::onButtonDownPress_setup(Button2 &t_button)
	{
		if (!m_screen.isEditingElement())
		{
			m_screen.selectNextElem();
		}
	}

	void MainController::onRotaryButtonPress_setup(Button2 &t_button)
	{
		if (m_screen.getCurrentElementID() == UVO_Components::GUISlice::E_ELEM_SETUP_Start)
		{
			//TODO FIX ERROR ON SWITCHING SCREEN
			setSystemState(UVO_Components::e_systemState::Monitor);
			sendSetupSettings();
		}
		else {
			m_screen.toggleEditSelectedElem();
		}
	}

	void MainController::onRotaryRight_setup(ESPRotary &t_rotary)
	{
		if (m_screen.isEditingElement())
		{
			changeSettingElement(1);
		}
		else
		{
			m_screen.selectNextElem();
		}
	}

	void MainController::onRotaryLeft_setup(ESPRotary &t_rotary)
	{
		if (m_screen.isEditingElement())
		{
			changeSettingElement(-1);
		}
		else
		{
			m_screen.selectPreviousElem();
		}
	}

	// *****************************************************
	//
	// 				UI HANDLING MONITOR SCREEN
	//
	// *****************************************************
	void MainController::onButtonUpPress_monitor(Button2 &t_button)
	{
	}

	void MainController::onButtonDownPress_monitor(Button2 &t_button)
	{
	}

	void MainController::onRotaryButtonPress_monitor(Button2 &t_button){
		if (m_screen.getCurrentElementID() == UVO_Components::GUISlice::E_ELEM_MONITOR_Stop){
			setSystemState(UVO_Components::e_systemState::Setup);
		}
		else if (m_screen.getCurrentElementID() == UVO_Components::GUISlice::E_ELEM_MONITOR_Pause)
		{
			// setSystemState(UVO_Components::e_systemState::Monitor);
			//TODO FIX
		}
	}

	void MainController::onRotaryRight_monitor(ESPRotary &t_rotary){
		m_screen.selectNextElem();
	}

	void MainController::onRotaryLeft_monitor(ESPRotary &t_rotary){
		m_screen.selectPreviousElem();
	}

#endif

}
