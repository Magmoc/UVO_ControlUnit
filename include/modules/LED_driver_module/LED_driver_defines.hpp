#ifndef LED_DRIVER_DEFINES_HPP
#define LED_DRIVER_DEFINES_HPP


namespace LED_Driver_defines {
	// Naming convention [name]_[IN/OUT/INOUT]_PIN

	const int OVERCURRENT_LED_FLAG_IN_PIN = D2;
	
	namespace LED_driver {
		const int PWM_255nm_OUT_PIN = D3;
		const int PWM_275nm_OUT_PIN = D5;
		const int PWM_285nm_OUT_PIN = D6;
		const int PWM_395nm_OUT_PIN = D9;

		const int LED_ENABLE_IN_PIN = D4;
	}

	namespace SPI {

		namespace VariableResistorType {
			enum TVariableResistorType : unsigned char {
				// [variable resistor in what sensor], [schematic name]
				currentSensor_285nm_GAIN = 1, // CS1 (Current Sensor X) 
				currentSensor_275nm_GAIN = 2, // CS2
				currentSensor_255nm_GAIN = 3, // CS3
				currentSensor_395nm_GAIN = 4, // CS4
				boostConverter_255nm_GAIN = 5, // BC1 (Boost Converter X)
				boostConverter_275nm_GAIN = 6, // BC2
				boostConverter_285nm_395nm = 7, // BC3
				ultraVioletSensor_GAIN = 8, // UVS 
				ozonComparisonSensor_COMPARE = 9, // OS (Ozon Sensor)
				seedTemperatureSensor_GAIN = 10, // TS (Temperature Sensor) 
			};
		}

		const int MOSI_OUT_PIN = D11;
		const int MISO_IN_PIN = D12;
		const int CLK_OUT_PIN = D13;

		const int MUX_UPDATE_OUT_PIN = D10;
		const int MUX_0_OUT_PIN = D7;
		const int MUX_1_OUT_PIN = D8;
		const int MUX_2_OUT_PIN = A3;
		const int MUX_3_OUT_PIN = A6;
	}

	namespace sensors {
		// Current sensors per wavelength are handled by I2C

		const int SEED_TEMPERATURE_IN_PIN = A0; // measures seed temperature using infrared
		const int ULTRAVIOLET_INTENSITY_IN_PIN = A1;
		const int OZON_MEASUREMENT_IN_PIN = A2;
		const int LEDS_TEMPERATURE_IN_PIN = A7; // measures LED temperature using thermistor
	}

	namespace I2C {
		//TODO FIX ADDRESSES
		const int ADDRESS = 0;

		const int SDA_INOUT_PIN = A4;
		const int SCL_INOUT_PIN = A5;
	}
}

#endif