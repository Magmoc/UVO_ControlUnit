#include "I2C_communication_test.hpp"
#include "components/communication/communication_protocol.hpp"




namespace UVO_UNIT_TESTS {
	void receive(int);
	void request(void);

	UNOTransceiver::UNOTransceiver(OperationMode t_operationMode, int t_I2C_address){
		m_operationMode = t_operationMode;
		m_I2C_address = t_I2C_address;
	}

	void UNOTransceiver::init(){
		slaveInit();
		Wire.begin(m_I2C_address);
		Serial.begin(9600);  // start serial for output
	}

	void UNOTransceiver::slaveInit(){
		// Wire.onRequest(requestEvent);
		// Wire.onReceive(receive);
		Wire.onRequest(request);
	}


	void UNOTransceiver::update(){
		slaveUpdate();
	}

	void receive(int){
		char data = Wire.read();
		Serial.println(data);
		Wire.write('Y');
	}

	void request(void){
		Wire.write('N');
	}

	void UNOTransceiver::slaveUpdate(void){
		delay(100);
	}
}