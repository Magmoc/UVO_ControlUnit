#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "communication/communication_protocol.hpp"

namespace UVO_Components {

struct Sensor {

	double last_read_value;

	const int module_type;
	const int module_address_I2C;

	union
	{
		const int I2C_address;
		const int SPI_chipselect;
	};
	
	union {
		const UVO_CommunicationProtocol::LEDDriverToken::SensorToken::TSensorToken LED_sensorToken;
		const UVO_CommunicationProtocol::MotorControlToken::SensorToken::TSensorToken Motor_sensorToken;
	};

};

//TODO: FIX ERROR WHERE APPEARANTLY THIS HAS ALREADY BEEN DEFINED
Sensor currentSensor_255nm = {
	.last_read_value = 0.0f,	// last_read_value

	.module_type = 0,	// module_type
	.module_address_I2C = UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS,	// module_address_I2C

	{
	.I2C_address = 0,	// I2C_address
	},

	{
	.LED_sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_255nm	// LED_sensorToken
	}
};

//TODO : All SENSOR DEFINES

}

#endif