#ifndef I2C_INTERFACE_HPP
#define I2C_INTERFACE_HPP

#include <Wire.h>
#include <Arduino.h>
#include <SPI.h>

//TODO MOVE TO SOMEWHERE ELSE
#define MAX_MESSAGE_LENGTH 10

namespace UVO_Components {

//TODO make I2C interface subclass of TwoWire
class I2CInterface
{
private:
	int m_SDA_pin;
	int m_SCL_pin;
	int m_I2C_address;
public:
	I2CInterface(int t_I2C_address);
	// I2CInterface(int t_I2C_address, int t_SDA_pin, int t_SCL_pin);
	~I2CInterface();
	
	void sendMessages(int address, byte* message, int message_length);
	int requestAndReadAnswer(int I2C_address, byte* receive_message, int bytes_requested);

	void onRequest( void (*t_function)(void) );
	void onReceive( void (*t_function)(int) );
};

}

#endif