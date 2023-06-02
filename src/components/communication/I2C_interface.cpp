#include "components/communication/I2C_interface.hpp"

// https://www.gammon.com.au/i2c


namespace UVO_Components {

I2CInterface::I2CInterface(int t_I2C_address){
	m_I2C_address = t_I2C_address;

	Wire.begin(m_I2C_address);
}

// I2CInterface::I2CInterface(int t_I2C_address, int t_SDA_pin, int t_SCL_pin){
// 	m_SDA_pin = t_SDA_pin;
// 	m_SCL_pin = t_SCL_pin;
// 	m_I2C_address = t_I2C_address;

// 	// Wire.begin(m_SDA_pin, m_SCL_pin, m_I2C_address);
// }


I2CInterface::~I2CInterface(){
	Wire.end();
}

void I2CInterface::sendMessages(int address, byte* message, int message_length){
	Wire.beginTransmission(address);
	Wire.write(message, (size_t) message_length);
	Wire.endTransmission();

	//TODO fix error checking
	// return true;
}

int I2CInterface::requestAndReadAnswer(int I2C_address, byte* receive_message, int bytes_requested){
	int num_bytes_received = Wire.requestFrom(I2C_address, bytes_requested);
	
	if(Wire.available()){
		Wire.readBytes(receive_message, num_bytes_received);
	}

	return num_bytes_received;
}

void onRequest( void (*t_function)(void) ){
	Wire.onRequest(t_function);
}

void onReceive( void (*t_function)(int) ){
	Wire.onReceive(t_function);
}

// https://forum.arduino.cc/t/multiple-bytes-read-of-i2c/57341/6

// bool CommunicationInterface::onReceiveMessageI2C(void){
// 	// https://forum.arduino.cc/t/send-float-over-i2c/424351

// 	// byte* px = (byte*)&x;


}