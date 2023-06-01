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

void MainCommunicationInterface::update(void){
	double received_data;

	received_data = requestSensorData(UVO_CommunicationProtocol::sensors::current_sensor_255nm);

	Serial.println(received_data);

	delay(1000);
}

int MainCommunicationInterface::sendMessageAndReadResponse(int t_I2C_slave_address, byte* t_message, int t_message_length, int t_bytes_requested, byte* t_response_data){
	int response_length;
	
	m_I2C_Interface.sendMessages(t_I2C_slave_address, t_message, t_message_length);

	response_length = m_I2C_Interface.requestAndReadAnswer(t_I2C_slave_address, t_response_data, t_bytes_requested);

	// if (response_length != t_bytes_requested){
	// 	//TODO Add log here.
	// }

	return response_length;
}

double MainCommunicationInterface::requestSensorData(UVO_CommunicationProtocol::Sensor t_sensor){

	double response = 0;
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

//TODO fix
// Use I2C interface and SPI interface for default communication
// that way you can later switch them very easily if you need a differnet protocol
// then define communication interfaces per module with the different types of functions
// so for example
// 		request sensor data
//		send sensor data
//		set pwm
// 		receive pwm signal
// 		

//bool MainCommunicationInterface::setPWMDutyCycle(Driver driver, int pwm){

// }

}
