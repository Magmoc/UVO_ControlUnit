// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#ifndef _SENSOR_HPP
#define _SENSOR_HPP

#include "components/communication/communication_protocol.hpp"

namespace UVO_CommunicationProtocol {

struct Sensor {
	int module_address_I2C;
	UVO_CommunicationProtocol::TSensorToken sensorToken;
};

// https://stackoverflow.com/questions/14425262/why-include-guards-do-not-prevent-multiple-function-definitions/14425299#14425299
// Therefore using the inline keyword
namespace sensors {
	namespace TOP_LEDDriver {
		inline const Sensor current_sensor_255nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_255nm,
		};
		
		inline const Sensor current_sensor_275nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_275nm,
		};
		
		inline const Sensor current_sensor_285nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_285nm,
		};
		
		inline const Sensor current_sensor_395nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_395nm,
		};
		
		inline const Sensor seed_temperature_sensor = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::SEED_TEMPERATURE_SENSOR,
		};
		
		inline const Sensor ultraviolet_intensity_sensor = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::ULTRAVIOLET_INTENSITY_SENSOR,
		};
		
		inline const Sensor ozon_sensor = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::OZONE_SENSOR,
		};
		
		inline const Sensor LEDs_temperature_sensor = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::LEDS_TEMPERATURE_SENSOR,
		};	
	}

	namespace BOTTOM_LEDDriver {
		inline const Sensor current_sensor_255nm = {
			.module_address_I2C = UVO_CommunicationProtocol::BOTTOM_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_255nm,
		};
		
		inline const Sensor current_sensor_275nm = {
			.module_address_I2C = UVO_CommunicationProtocol::BOTTOM_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_275nm,
		};
		
		inline const Sensor current_sensor_285nm = {
			.module_address_I2C = UVO_CommunicationProtocol::BOTTOM_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_285nm,
		};
		
		inline const Sensor current_sensor_395nm = {
			.module_address_I2C = UVO_CommunicationProtocol::BOTTOM_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::CURRENTSENSOR_395nm,
		};
		
		inline const Sensor seed_temperature_sensor = {
			.module_address_I2C = UVO_CommunicationProtocol::BOTTOM_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::SEED_TEMPERATURE_SENSOR,
		};
		
		inline const Sensor ultraviolet_intensity_sensor = {
			.module_address_I2C = UVO_CommunicationProtocol::BOTTOM_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::ULTRAVIOLET_INTENSITY_SENSOR,
		};
		
		inline const Sensor ozon_sensor = {
			.module_address_I2C = UVO_CommunicationProtocol::BOTTOM_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::OZONE_SENSOR,
		};
		
		inline const Sensor LEDs_temperature_sensor = {
			.module_address_I2C = UVO_CommunicationProtocol::BOTTOM_LED_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::LEDDriverToken::SensorToken::LEDS_TEMPERATURE_SENSOR,
		};
		
	}

	namespace motor_controller{
		inline const Sensor current_sensor_motor = {
			.module_address_I2C = UVO_CommunicationProtocol::MOTOR_CONTROLLER_ADDRESS,
			.sensorToken = UVO_CommunicationProtocol::MotorControlToken::SensorToken::CURRENTSENSOR_MOTOR,
		};
	}
};

}

#endif