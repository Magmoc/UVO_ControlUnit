// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#include "components/communication/I2C_interface.hpp"

// https://www.gammon.com.au/i2c


namespace UVO_Components {

I2CInterface::I2CInterface(int t_I2C_address){
	m_I2C_address = t_I2C_address;

	// Wire.setPins()
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
	//TODO CHECK OUT IF requestFrom can also be implemented using restart=false
	int num_bytes_received = Wire.requestFrom(I2C_address, bytes_requested);
	
	//TODO MULTILPE CHECKS
	if(Wire.available()){
		Wire.readBytes(receive_message, num_bytes_received);
	}

	//TODO RETURN OPTIONAL VALUE IF ERROR FOR EXAMPLE
	return num_bytes_received;
}

void I2CInterface::onRequest( void (*t_function)(void) ){
	Wire.onRequest(t_function);
}

void I2CInterface::onReceive( void (*t_function)(int) ){
	Wire.onReceive(t_function);
}

}