#ifndef SPI_INTERFACE_HPP
#define SPI_INTERFACE_HPP

#include <Wire.h>
#include <Arduino.h>
#include <SPI.h>

#define MAX_MESSAGE_LENGTH 10

namespace UVO_Components {

class SPIInterface
{
private:
	byte m_receiveValueArray[MAX_MESSAGE_LENGTH];
	int m_receiveValueLength;

	int m_receiveValueInt;
	float m_receiveValueFloat; 
public:
	SPIInterface(/* args */);
	~SPIInterface();
	bool sendMessages(int address, byte* message, int message_length);
	int requestAndReadAnswer(int I2C_address, byte* receive_message, int message_length);

};

}

#endif