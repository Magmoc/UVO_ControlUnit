// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

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
		Wire.onReceive(receive);
		Wire.onRequest(request);
	}


	void UNOTransceiver::update(){
		slaveUpdate();
	}

	void receive(int){
		UVO_CommunicationProtocol::TPackageTypeToken packageType;
		packageType = (UVO_CommunicationProtocol::TPackageTypeToken) Wire.read();
		Serial.println(packageType);

		while(Wire.available()){
			Serial.println(Wire.read());
		}		
	}

	void request(void){
		double test = 1.5f;
		byte* tp = (byte*) &test;
		Wire.write(tp, sizeof(test));
	}

	void UNOTransceiver::slaveUpdate(void){
		delay(100);
	}
}