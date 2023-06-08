#ifndef SENSOR_HPP
#define SENSOR_HPP

#include "components/communication/communication_protocol.hpp"

namespace UVO_CommunicationProtocol {

struct Sensor {
	int module_address_I2C;
	UVO_CommunicationProtocol::TSensorToken sensorToken;
};

namespace sensors {
	inline Sensor current_sensor_255nm = {
		.module_address_I2C = UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS,
		.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_255nm,
	};
	
	inline Sensor current_sensor_275nm = {
		.module_address_I2C = UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS,
		.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_275nm,
	};
	
	inline Sensor current_sensor_285nm = {
		.module_address_I2C = UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS,
		.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_285nm,
	};
	
	inline Sensor current_sensor_395nm = {
		.module_address_I2C = UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS,
		.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_395nm,
	};
	
	inline Sensor seed_temperature_sensor = {
		.module_address_I2C = UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS,
		.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::SEED_TEMPERATURE_SENSOR,
	};
	
	inline Sensor ultraviolet_intensity_sensor = {
		.module_address_I2C = UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS,
		.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::ULTRAVIOLET_INTENSITY_SENSOR,
	};
	
	inline Sensor ozon_sensor = {
		.module_address_I2C = UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS,
		.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::OZON_SENSOR,
	};
	
	inline Sensor LEDs_temperature_sensor = {
		.module_address_I2C = UVO_CommunicationProtocol::LED_CONTROLLER_ADDRESS,
		.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::LEDS_TEMPERATURE_SENSOR,
	};
	
	inline Sensor current_sensor_motor = {
		.module_address_I2C = UVO_CommunicationProtocol::MOTOR_CONTROLLER_ADDRESS,
		.sensorToken = UVO_CommunicationProtocol::MotorControlToken::SensorToken::CURRENTSENSOR_MOTOR,
	};
	
};

}

#endif