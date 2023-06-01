#ifndef MAIN_CONTROLLER_COMMUNICATION_INTERFACE_H
#define MAIN_CONTROLLER_COMMUNICATION_INTERFACE_H

#include <Wire.h>
#include <Arduino.h>
#include "components/communication/communication_protocol.hpp"
#include "components/communication/I2C_interface.hpp"
#include "components/sensor.hpp"

namespace UVO_MainController {

class MainCommunicationInterface{
private:
	UVO_Components::I2CInterface m_I2C_Interface;
	int sendMessageAndReadResponse(int t_I2C_slave_address, byte* t_message, int t_message_length, int t_bytes_requested, byte* t_response_data);
	
public:
	MainCommunicationInterface(int t_I2C_address);
	~MainCommunicationInterface();

	// TODO IMPLEMENT IF NEEDED
	// void MainCommunicationInterface::setSDA(int SDA_pin);
	// void MainCommunicationInterface::setSCL(int SCL_pin);

	void init(void);
	void update(void);
	double requestSensorData(UVO_CommunicationProtocol::Sensor t_sensor);

};

}

#endif