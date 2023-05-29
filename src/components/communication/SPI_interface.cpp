#include "components/communication/SPI_interface.hpp"

// https://www.gammon.com.au/i2c

namespace UVO_Components {

SPIInterface::SPIInterface(/* args */){
	// TODO Fix setup
	// Wire.begin(sda, scl, address);
}

SPIInterface::~SPIInterface(){

}

bool SPIInterface::sendMessages(int address, byte* message, int message_length){
	Wire.beginTransmission(address);
	Wire.write(message, (size_t) message_length);
	Wire.endTransmission();

	return true;
}

int SPIInterface::requestAndReadAnswer(int I2C_address, byte* receive_message, int message_length){
	int num_bytes_received = Wire.requestFrom(I2C_address, message_length);
	Wire.readBytes( (uint8_t *) receive_message, num_bytes_received);

	return num_bytes_received;
}



// int CommunicationInterface::requestAndReadAnswer(int SPI_chipSelect, byte* receive_message, int message_length){
// 	//TODO implement SPI request data.
// }

// https://forum.arduino.cc/t/multiple-bytes-read-of-i2c/57341/6
// uint16_t CommunicationInterface::requestMultipleBytes(int I2C_address, int message_length, byte* receiveMessage)
// {
//     uint16_t bytes_received = 0;
//     uint16_t bytes_requested = message_length;

//     Wire.beginTransmission(I2C_address);

//     Wire.endTransmission();

//     Wire.requestFrom(I2C_address ,bytes_requested);
//     uint16_t remaining = bytes_requested;
//     uint8_t* next = receiveMessage;

//     while (Wire.available() && remaining--)
//     {
//         *next++ = Wire.readBytes();
//         ++bytes_received;
//     }

//     return bytes_received;
// }

// bool CommunicationInterface::onReceiveMessageI2C(void){
// 	// https://forum.arduino.cc/t/send-float-over-i2c/424351

// 	// byte* px = (byte*)&x;
// }

// bool CommunicationInterface::sendMessageSPI(int chipSelect, byte* message, int message_length){

// }

// bool CommunicationInterface::onReceiveMessageSPI(void){

// }

}