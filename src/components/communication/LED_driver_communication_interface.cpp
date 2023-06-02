//TODO TRY:
// ON REQUEST FROM MAIN CONTROLLER
// 			REQUEST FROM SENSOR
// 				READ OUT CURRENT SENSOR
// 			ANSWER MAIN CONTROLLER

//TODO FIND LIB FOR THIS ADC

#include "components/communication/LED_driver_communication_interface.hpp"

//TODO Rename namespaces to UVO_LEDDriver?
namespace UVO_LEDDriverController {

	LEDDriverCommunicationInterface::LEDDriverCommunicationInterface(int t_I2C_address)
		: m_I2C_Interface(t_I2C_address)
	{

	}
	
	LEDDriverCommunicationInterface::~LEDDriverCommunicationInterface(){

	}
	
	
	void LEDDriverCommunicationInterface::init(void){
		
	}	
	
	void LEDDriverCommunicationInterface::update(void){

	}


}