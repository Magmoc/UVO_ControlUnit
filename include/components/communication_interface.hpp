#ifndef COMMUNICATION_INTERFACE_HPP
#define COMMUNICATION_INTERFACE_HPP

#include <Wire.h>
#include <Arduino.h>
#include <SPI.h>

#define MAX_MESSAGE_LENGTH 10

namespace UVO_Components {

class CommunicationInterface
{
private:
	byte m_receiveValueArray[MAX_MESSAGE_LENGTH];
	int m_receiveValueLength;

	int m_receiveValueInt;
	float m_receiveValueFloat; 
public:
	CommunicationInterface(/* args */);
	~CommunicationInterface();
	bool sendMessageI2C(int address, byte* message, int message_length);
	bool onReceiveMessageI2C(void);
	int requestMessage(int I2C_address, byte* receive_message, int message_length);
	int requestMessage(int SPI_chipSelect, byte* receive_message, int message_length);


	bool sendMessageSPI(int chipSelect, byte* message, int message_length);
	bool onReceiveMessageSPI(void);
};

}

#endif