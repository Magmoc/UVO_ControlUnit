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
	byte data_array[MAX_MESSAGE_LENGTH] = {0};
	byte* received_data = data_array;
	int bytes_received = 0;

	Serial.print("INIT VALUE RECEIVED DATA ");
	Serial.println(received_data[0]);

	// bytes_received = requestSensorData(UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS, received_data);
	bytes_received = requestSensorData(UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS, received_data);
	
	Serial.print("Index: ");
	Serial.println(bytes_received);
	for (int i = 0; i < bytes_received; i++){
		
		Serial.println((char) received_data[i]);
	}
	Serial.println("-------------------");
	delay(2000);
}

// int MainCommunicationInterface::requestSensorData(int t_I2C_slave_address, byte* t_received_data){

// }

int MainCommunicationInterface::requestSensorData(int t_I2C_slave_address, byte* t_received_data){
	int received_length = 0;

	byte message[] = {UVO_CommunicationProtocol::REQUEST_SENSOR_DATA_IDENTIFIER};
	int message_length = sizeof(message) / sizeof(message[0]);

	// TODO FIX PROTOCOL DEFINITIONS
	// int bytes_requested = message_length*4;
	int bytes_requested = 1;

	m_I2C_Interface.sendMessages(t_I2C_slave_address, message, message_length);

	received_length = m_I2C_Interface.requestAndReadAnswer(t_I2C_slave_address, t_received_data, bytes_requested);

	// if (received_length != bytes_requested){
	// 	return bytes_requested;
	// 	//TODO Add log here.
	// }

	return received_length;
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

//bool MainCommunicationInterface::requestSensorData(Sensor sensor){
// send address
// request data
// save data in byte array
// convert to proper data type
// store data in sensor
// }

//bool MainCommunicationInterface::setPWMDutyCycle(Driver driver, int pwm){

// }

}
