#ifndef COMMUNICATION_PROTOCOL_HPP
#define COMMUNICATION_PROTOCOL_HPP


//TODO MOVE ALL DEFINITIONS TO OTHER FILE?
namespace UVO_CommunicationProtocol {

	const int MAIN_CONTROLLER_ADDRESS = 40;
	const int LED_CONTROLLER_ADDRESS = 60;
	const int MOTOR_CONTROLLER_ADDRESS = 80;

	const char REQUEST_SENSOR_DATA_IDENTIFIER = 'S';


}


// ********************************************************************
//  Request (R) Sensor Data 

// MOTOR:
// 		current sensor

// LED SENSOR:
// 		10 chip selects
// CS 1 : Current Sensor 1
// CS 2 : Current Sensor 2
// CS 3 : Current Sensor 3
// CS 4 : Current Sensor 4
// CS 5 : Boost Converter 1
// CS 6 : Boost Converter 2
// CS 7 : Boost Converter 3
// CS 8 : UV Sensor
// CS 9 : Ozon Sensor
// CS 10 : Temperature Sensor

// Set (S) PWM
// 

#endif