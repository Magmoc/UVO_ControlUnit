// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#ifndef _DRIVER_HPP
#define _DRIVER_HPP

#include "components/communication/communication_protocol.hpp"

namespace UVO_CommunicationProtocol {

struct Driver {
	int module_address_I2C;
	UVO_CommunicationProtocol::TDriverToken driverToken;
};

// https://stackoverflow.com/questions/14425262/why-include-guards-do-not-prevent-multiple-function-definitions/14425299#14425299
// Therefore using the inline keyword
namespace drivers {
	namespace TOP_LEDDriver {
		inline const Driver pwm_driver_255nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.driverToken = UVO_CommunicationProtocol::LEDDriverToken::DriverToken::PWM_255nm,
		};
		inline const Driver pwm_driver_275nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.driverToken = UVO_CommunicationProtocol::LEDDriverToken::DriverToken::PWM_275nm,
		};
		inline const Driver pwm_driver_285nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.driverToken = UVO_CommunicationProtocol::LEDDriverToken::DriverToken::PWM_285nm,
		};
		inline const Driver pwm_driver_395nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.driverToken = UVO_CommunicationProtocol::LEDDriverToken::DriverToken::PWM_395nm,
		};
	}

	namespace BOTTOM_LEDDriver {
		inline const Driver pwm_driver_255nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.driverToken = UVO_CommunicationProtocol::LEDDriverToken::DriverToken::PWM_255nm,
		};
		inline const Driver pwm_driver_275nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.driverToken = UVO_CommunicationProtocol::LEDDriverToken::DriverToken::PWM_275nm,
		};
		inline const Driver pwm_driver_285nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.driverToken = UVO_CommunicationProtocol::LEDDriverToken::DriverToken::PWM_285nm,
		};
		inline const Driver pwm_driver_395nm = {
			.module_address_I2C = UVO_CommunicationProtocol::TOP_LED_CONTROLLER_ADDRESS,
			.driverToken = UVO_CommunicationProtocol::LEDDriverToken::DriverToken::PWM_395nm,
		};
	}

	namespace motor_controller{
		inline const Driver pwm_motor = {
			.module_address_I2C = UVO_CommunicationProtocol::MOTOR_CONTROLLER_ADDRESS,
			.driverToken = UVO_CommunicationProtocol::MotorControlToken::DriverToken::PWM_MOTOR,
		};
	}
};

}

#endif