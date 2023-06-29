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


#include "modules/control_module/main_controller_defines.hpp"

namespace UVO_Components {
I2CInterface::I2CInterface(void){

}

I2CInterface::I2CInterface(int t_I2C_address){
	init(t_I2C_address);
}

void I2CInterface::init(int t_I2C_address){
	m_I2C_address = t_I2C_address;

	//TODO MOVE
	noInterrupts();
	Wire.setPins(SDA_PIN, SCL_PIN);
	// Wire.begin(m_I2C_address);

	// Cannot initialise using I2C address
	// that is only possible for targets.
	Wire.begin();
	interrupts();
}

// I2CInterface::I2CInterface(int t_I2C_address, int t_SDA_pin, int t_SCL_pin){
// 	m_SDA_pin = t_SDA_pin;
// 	m_SCL_pin = t_SCL_pin;
// 	m_I2C_address = t_I2C_address;

// 	// Wire.begin(m_SDA_pin, m_SCL_pin, m_I2C_address);
// }


I2CInterface::~I2CInterface(){
	noInterrupts();
	Wire.end();
	interrupts();
}

void I2CInterface::sendMessages(int address, byte* message, int message_length){
	noInterrupts();
	Wire.beginTransmission(address);
	Wire.write(message, (size_t) message_length);
	Wire.endTransmission();
	interrupts();

	//TODO fix error checking
	// return true;
}

int I2CInterface::requestAndReadAnswer(int I2C_address, byte* receive_message, int bytes_requested){
	
	noInterrupts();
	
	//TODO CHECK OUT IF requestFrom can also be implemented using restart=false
	// bool stop = true;
	// int num_bytes_received = Wire.requestFrom(I2C_address, bytes_requested, (int) stop);
	int num_bytes_received = Wire.requestFrom(I2C_address, bytes_requested);
	
	//TODO MULTILPE CHECKS
	while(!Wire.available()){
		// Wait for response
	}
	
	Wire.readBytes(receive_message, num_bytes_received);

	interrupts();

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