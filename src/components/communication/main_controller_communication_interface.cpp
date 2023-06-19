// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#include "components/communication/main_controller_communication_interface.hpp"

namespace UVO_MainController {

MainCommunicationInterface::MainCommunicationInterface(int t_I2C_address)
	: m_I2C_Interface(t_I2C_address)
{

}

MainCommunicationInterface::~MainCommunicationInterface(){

}

void MainCommunicationInterface::init(void){

}


// TODO: IMPLEMENT https://forum.arduino.cc/t/how-to-properly-use-wire-onreceive/891195/2
void MainCommunicationInterface::update(void){

}

int MainCommunicationInterface::sendMessageAndReadResponse(int t_I2C_slave_address, byte* t_message, int t_message_length, int t_bytes_requested, byte* t_response_data){
	int response_length;
	
	m_I2C_Interface.sendMessages(t_I2C_slave_address, t_message, t_message_length);

	response_length = m_I2C_Interface.requestAndReadAnswer(t_I2C_slave_address, t_response_data, t_bytes_requested);

	if (response_length != t_bytes_requested){
		//TODO Add log here.
	}

	return response_length;
}

float MainCommunicationInterface::requestSensorData(UVO_CommunicationProtocol::Sensor t_sensor){

	float response = 0;
	int bytes_requested = sizeof(response);
	byte* response_pointer = (byte*) &response;

	int received_length = 0;

	int I2C_address = t_sensor.module_address_I2C;
	
	byte message[] = {UVO_CommunicationProtocol::PackageTypeToken::REQUEST_SENSOR_DATA, t_sensor.sensorToken};
	int message_length = sizeof(message) / sizeof(message[0]);

	received_length = sendMessageAndReadResponse(I2C_address, message, message_length, bytes_requested, response_pointer);

	if (received_length != bytes_requested){
		// TODO LOG SOMETHING IS WRONG
	}


	return response;
}

bool MainCommunicationInterface::setPWMDutyCycle(UVO_CommunicationProtocol::Driver t_driver, uint8_t t_pwm){
	int bytes_requested = sizeof(t_pwm);
	int received_length = 0;

	bool response = false;
	byte* pointer = (byte*) &response;

	int I2C_address = t_driver.module_address_I2C;
	
	byte message[] = {UVO_CommunicationProtocol::PackageTypeToken::SET_DRIVER_INTENSITY, t_driver.driverToken, t_pwm};
	int message_length = sizeof(message) / sizeof(message[0]);

	received_length = sendMessageAndReadResponse(I2C_address, message, message_length, bytes_requested, pointer);

	if (received_length != bytes_requested){
		// TODO LOG SOMETHING IS WRONG
	}


	return response;
}

}
