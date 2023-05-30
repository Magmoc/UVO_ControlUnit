#ifndef COMMUNICATION_PROTOCOL_HPP
#define COMMUNICATION_PROTOCOL_HPP


namespace UVO_CommunicationProtocol {
	// [REQUEST_SENSOR_DATA] [SENSOR_TOKEN] REQUEST [value (double)]
	// [SET_DRIVER_INTENSITY] [DRIVER_TOKEN] REQUEST [ack (byte)]
	// [SET_VARIABLE_RESISTOR] [RESISTOR_TOKEN] REQUEST [ack (byte)]

	const int MAIN_CONTROLLER_ADDRESS = 40;
	const int LED_CONTROLLER_ADDRESS = 60;
	const int MOTOR_CONTROLLER_ADDRESS = 80;

	namespace PackageTypeToken {
		enum TPackageTypeToken : unsigned char {
			REQUEST_SENSOR_DATA = 'S',
			SET_DRIVER_RELATIVE_INTENSITY = 'D',
			SET_VARIABLE_RESISTOR = 'R',
		};
	}

	namespace LEDDriverToken {
		//TODO What do we measure at every sensor? What are the conversions

		namespace SensorToken {
			enum TSensorToken : unsigned char {
				CURRENTSENSOR_255nm = 1,
				CURRENTSENSOR_275nm = 2,
				CURRENTSENSOR_285nm = 4,
				CURRENTSENSOR_395nm = 8,

				SEED_TEMPERATURE = 16,
				ULTRAVIOLET_INTENSITY = 32,
				OZON_MEASUREMENT = 64,
				LEDS_TEMPERATURE = 128,

				INVALID = 255,
			};
		}

		namespace DriverToken {
			enum TDriverToken : unsigned char {
				PWM_255nm = 1,
				PWM_265nm = 2,
				PWM_275nm = 4,
				PWM_395nm = 8,

				INVALID = 255,
			};
		}
		
		namespace VariableResistorToken {
			enum TVariableResistorToken : unsigned char {
				CURRENTSENSOR_285nm = 1, // CS1 (Current Sensor X) 
				CURRENTSENSOR_275nm = 2, // CS2
				CURRENTSENSOR_255nm = 4, // CS3
				CURRENTSENSOR_395nm = 8, // CS4

				BOOSTCONVERTER_255nm = 3, // BC1 (Boost Converter X)
				BOOSTCONVERTER_275nm = 6, // BC2
				BOOSTCONVERTER_285nm_395nm = 12, // BC3
				
				ULTRAVIOLETSENSOR = 7, // UVS 
				OZONSENSOR = 14, // OS (Ozone Sensor)
				SEEDTEMPERATURESENSOR = 28, // TS (Temperature Sensor) 

				INVALID = 255,
			};
		}
	}

	namespace MotorControlToken {
		//TODO What do we measure at every sensor? What are the conversions

		enum TSensorToken : unsigned char {
			CURRENTSENSOR_MOTOR = 1,
			INVALID = 255,
		};

		enum TDriverToken : unsigned char {
			PWM_MOTOR = 1,

		};
	}



}

#endif