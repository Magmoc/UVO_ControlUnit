#ifndef MAIN_CONTROLLER_COMMUNICATION_INTERFACE_H
#define MAIN_CONTROLLER_COMMUNICATION_INTERFACE_H

#include <Wire.h>
#include <Arduino.h>
#include "components/communication/communication_protocol.hpp"
#include "components/communication/I2C_interface.hpp"

namespace UVO_MainController {

class MainCommunicationInterface{
private:
	UVO_Components::I2CInterface m_I2C_Interface;
public:
	MainCommunicationInterface(int t_I2C_address);
	~MainCommunicationInterface();

	// TODO IMPLEMENT IF NEEDED
	// void MainCommunicationInterface::setSDA(int SDA_pin);
	// void MainCommunicationInterface::setSCL(int SCL_pin);

	void init(void);
	void update(void);
	int requestSensorData(int t_I2C_slave_address, byte* t_received_data);

};

}

#endif