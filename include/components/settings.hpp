#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <stdint.h>
#include <limits.h>
#include <time.h>

namespace UVO_Components {

	struct s_setupSettings
	{
		bool isUpdated = false;

		uint8_t LED_intensity_255nm = 0;
		uint8_t LED_intensity_275nm = 0;
		uint8_t LED_intensity_285nm = 0;
		uint8_t LED_intensity_395nm = 0;

		uint8_t motor_intensity = 0;

		time_t targetExposureTime = 0;

		int globalSampleFrequencyHz = 10;

		void addSeconds(int seconds){
			// Must be ulong type.
			ulong new_time = targetExposureTime + seconds;

			//clamp
			time_t maxTime = ULONG_MAX;
			time_t minTime = 0;
			new_time = (new_time > maxTime) ? maxTime : new_time;
			new_time = (new_time < minTime) ? minTime : new_time;

			targetExposureTime = new_time;
		}

		void addMinutes(int minutes){
			addSeconds(60*minutes);
		}

		void addHours(int hours){
			addMinutes(60*hours);
		}
	};

	struct s_systemState {
		s_setupSettings SetupSettings;
		volatile bool isUpdated = false;
		long int elapsedExposureTime = 0;

	};
	
}

#endif