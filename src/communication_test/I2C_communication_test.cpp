#include "I2C_communication_test.h"

namespace UVO_UNIT_TESTS {
	UNOTransceiver::UNOTransceiver(OperationMode t_operationMode){
		m_operationMode = t_operationMode;
	}

	void UNOTransceiver::init(){
		Wire.begin();        // join i2c bus (address optional for master)
		Serial.begin(9600);  // start serial for output
	}

	void UNOTransceiver::update(){
//   Wire.requestFrom(8, 6);    // request 6 bytes from peripheral device #8
//   while (Wire.available()) { // peripheral may send less than requested
//     char c = Wire.read(); // receive a byte as character

	}
	



}