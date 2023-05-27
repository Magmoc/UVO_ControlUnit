#ifndef COMMUNICATION_INTERFACE_HPP
#define COMMUNICATION_INTERFACE_HPP

#include <Wire.h>
#include <Arduino.h>
#include <SPI.h>

#define MAX_MESSAGE_LENGTH 10

namespace UVO_Components {

class I2CInterface
{
private:
	int m_SDA_pin;
	int m_SCL_pin;
	int m_I2C_address;
public:
	I2CInterface(int t_I2C_address);
	I2CInterface(int t_I2C_address, int t_SDA_pin, int t_SCL_pin);
	~I2CInterface();
	
	bool sendMessage(int address, byte* message, int message_length);
	int requestMessage(int I2C_address, byte* receive_message, int message_length);
};

}

#endif