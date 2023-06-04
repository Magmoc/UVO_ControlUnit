#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <stdint.h>

namespace UVO_Components {

	struct settings
	{
		volatile uint8_t isUpdated = 0;

		uint8_t LED_intensity_255nm = 0;
		uint8_t LED_intensity_275nm = 0;
		uint8_t LED_intensity_285nm = 0;
		uint8_t LED_intensity_395nm = 0;

		uint8_t motor_intensity = 0;

		long int targetExposureTime = 0;
		long int currentExposureTime = 0;

		int globalSampleFrequencyHz = 10;
	};
	


}

#endif