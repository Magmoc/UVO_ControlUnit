#ifndef LED_DRIVER_DEFINES_HPP
#define LED_DRIVER_DEFINES_HPP


namespace LED_Driver_defines {
	// Naming convention [name]_[IN/OUT]_PIN

	const int OVERCURRENT_LED_FLAG_IN_PIN = D2;
	
	namespace LED_driver {
		const int PWM_255_OUT_PIN = D3;
		const int PWM_275_OUT_PIN = D5;
		const int PWM_285_OUT_PIN = D6;
		const int PWM_395_OUT_PIN = D9;

		const int LED_ENABLE_IN_PIN = D4;
	}

	namespace SPI {
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
		const int SEED_TEMPERATURE_IN_PIN = A0; // measures seed temperature using infrared
		const int ULTRAVIOLET_INTENSITY_IN_PIN = A1;
		const int OZON_MEASUREMENT_IN_PIN = A2;
		const int LED_TEMPERATURE_IN_PIN = A7; // measures LED temperature using thermistor
	}

	namespace I2C {
		const int SDA_OUT_PIN = A4;
		const int SCL_OUT_PIN = A5;
	}
}

#endif