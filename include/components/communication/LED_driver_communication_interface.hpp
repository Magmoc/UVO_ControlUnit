#ifndef LED_DRIVER_COMMUNICATION_INTERFACE_H
#define LED_DRIVER_COMMUNICATION_INTERFACE_H

#include <Wire.h>
#include <Arduino.h>
#include "components/communication/communication_protocol.hpp"
#include "components/communication/I2C_interface.hpp"
#include "components/sensor.hpp"

namespace UVO_LEDDriverController {

//TODO fix names

//TODO LED COMMUNICATION MANAGER HANDLES OWN REQUESTS. THis enables the option of threading. DECENTRALIZED.
class LEDDriverCommunicationInterface {
private:
	UVO_Components::I2CInterface m_I2C_Interface;


	//TODO IMPLEMENT USING ARRAY
	volatile UVO_CommunicationProtocol::TToken received_messages[MAX_MESSAGE_LENGTH] = {UVO_CommunicationProtocol::INVALID};
	

	int sendMessageAndReadResponse(int t_I2C_slave_address, byte* t_message, int t_message_length, int t_bytes_requested, byte* t_response_data);
	
public:
	//TODO change variable name so that it becomes clear that it is the I2C address of the unit itself
	LEDDriverCommunicationInterface(int t_I2C_address);
	~LEDDriverCommunicationInterface();

	void init(void);
	void update(void);

	double readSensorData(UVO_CommunicationProtocol::Sensor t_sensor);

	void getLastPackage(void);

	int newPackageArrived;
};

}

#endif