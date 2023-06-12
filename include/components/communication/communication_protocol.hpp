#ifndef COMMUNICATION_PROTOCOL_HPP
#define COMMUNICATION_PROTOCOL_HPP


namespace UVO_CommunicationProtocol {
	// https://stackoverflow.com/questions/112433/should-i-use-define-enum-or-const

	// Sent from Control Unit
	// [REQUEST_SENSOR_DATA] [SENSOR_TOKEN] REQUEST [value (double) (4 bytes)]
	// [SET_DRIVER_INTENSITY] [DRIVER_TOKEN] [uint_8 intensity (0-255)] REQUEST [ack (byte)]
	// [SET_VARIABLE_RESISTOR] [RESISTOR_TOKEN] [uint_8 intensity (0-255)] REQUEST [ack (byte)]


	//TODO We need to discuss this later, whether we want to implement this
	//TODO Who does error handling? Control module or submodule?
	// Sent to Control Unit
	// [SEND_ERROR_FLAG] [YOUR OWN I2C ADDRESS] [SENSOR_TOKEN] REQUEST [ack (byte)]

	const int MAIN_CONTROLLER_ADDRESS = 40;
	const int TOP_LED_CONTROLLER_ADDRESS = 60;
	const int BOTTOM_LED_CONTROLLER_ADDRESS = 61;
	const int MOTOR_CONTROLLER_ADDRESS = 80;

	typedef unsigned char TToken;
	typedef TToken TPackageTypeToken;
	typedef TToken TSensorToken;
	typedef TToken TDriverToken;
	typedef TToken TVariableResistorToken;

	const TToken ACK = 2;
	const TToken NACK = 4;

	const TToken INVALID = 255;

	namespace PackageTypeToken {
		const TPackageTypeToken REQUEST_SENSOR_DATA = 'S';
		const TPackageTypeToken SET_DRIVER_INTENSITY = 'D';
		const TPackageTypeToken SET_VARIABLE_RESISTOR = 'R';
		const TPackageTypeToken SEND_ERROR_FLAG = 'E';
	}

	namespace LEDDriverToken {
		//TODO What do we measure at every sensor? What are the conversions

		namespace SensorToken {
			const TSensorToken CURRENTSENSOR_255nm = 1;
			const TSensorToken CURRENTSENSOR_275nm = 2;
			const TSensorToken CURRENTSENSOR_285nm = 4;
			const TSensorToken CURRENTSENSOR_395nm = 8;
			
			const TSensorToken SEED_TEMPERATURE_SENSOR = 16;
			const TSensorToken ULTRAVIOLET_INTENSITY_SENSOR = 32;
			const TSensorToken OZON_SENSOR = 64;
			const TSensorToken LEDS_TEMPERATURE_SENSOR = 128;
		}

		namespace DriverToken {
				const TDriverToken PWM_255nm = 1;
				const TDriverToken PWM_265nm = 2;
				const TDriverToken PWM_275nm = 4;
				const TDriverToken PWM_395nm = 8;				
		}
		
		namespace VariableResistorToken {
				const TVariableResistorToken CURRENTSENSOR_285nm = 1; // CS1 (Current Sensor X) 
				const TVariableResistorToken CURRENTSENSOR_275nm = 2; // CS2
				const TVariableResistorToken CURRENTSENSOR_255nm = 4; // CS3
				const TVariableResistorToken CURRENTSENSOR_395nm = 8; // CS4

				const TVariableResistorToken BOOSTCONVERTER_255nm = 3; // BC1 (Boost Converter X)
				const TVariableResistorToken BOOSTCONVERTER_275nm = 6; // BC2
				const TVariableResistorToken BOOSTCONVERTER_285nm_395nm = 12; // BC3

				const TVariableResistorToken ULTRAVIOLETSENSOR = 7; // UVS 
				const TVariableResistorToken OZONSENSOR = 14; // OS (Ozone Sensor)
				const TVariableResistorToken SEEDTEMPERATURESENSOR = 28; // TS (Temperature Sensor) 
		}
	}

	namespace MotorControlToken {
		//TODO What do we measure at every sensor? What are the conversions

		namespace SensorToken {
			const TSensorToken CURRENTSENSOR_MOTOR = 1;
		}

		namespace DriverToken {
			const TDriverToken PWM_MOTOR = 1;
		}
	}



}

#endif