#include "I2C_communication_test.h"

namespace UVO_UNIT_TESTS {
	UNOTransceiver::UNOTransceiver(OperationMode t_operationMode, int t_I2C_address){
		m_operationMode = t_operationMode;
		m_I2C_address = t_I2C_address;
	}

	void UNOTransceiver::init(){
		if (m_operationMode == MASTER_OPERATION_MODE){
			masterInit();
		}
		else{
			slaveInit();
		}
		
		Wire.begin(m_I2C_address);
		Serial.begin(9600);  // start serial for output
	}

	void UNOTransceiver::masterInit(){
	}

	void UNOTransceiver::slaveInit(){
		Wire.onRequest(requestEvent);
	}


	void UNOTransceiver::update(){
		if (m_operationMode == MASTER_OPERATION_MODE){
			masterUpdate();
		}
		else{
			slaveUpdate();
		}
	}

	void UNOTransceiver::masterUpdate(void){
		Wire.requestFrom(SLAVE_ADDRESS, 6);    // request 6 bytes from peripheral device #8
		while (Wire.available()) { // peripheral may send less than requested
			char c = Wire.read(); // receive a byte as character
			Serial.print(c);
		}
		Serial.println();
	}

	void UNOTransceiver::slaveUpdate(void){
		delay(100);
	}

	void requestEvent(void){
		Wire.write("Hello ");
	}

}