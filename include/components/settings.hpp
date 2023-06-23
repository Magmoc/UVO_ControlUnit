// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#ifndef _SETTINGS_HPP
#define _SETTINGS_HPP

#include <stdint.h>
#include <limits.h>
#include <time.h>

//TODO fix namespace
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
	
	struct s_monitorState
	{
		bool isUpdated = false;

		float LED_current_255nm = 0.0;
		float LED_current_275nm = 0.0;
		float LED_current_285nm = 0.0;
		float LED_current_395nm = 0.0;

		float temperature_seeds = 0.0;
		float temperature_leds_top = 0.0;
		float temperature_leds_bottom = 0.0;

		float UV_intensity = 0.0;
		float UV_dose = 0.0;
		float ozone_concentration_ppm = 0.0;

		time_t exposureTime = 0;
	};


	//TODO find other location
	enum systemState {systemState_setup, systemState_monitor};

	struct s_systemState {

		s_setupSettings SetupSettings;
		s_monitorState MonitorState;
		systemState state = systemState_setup;
		
		volatile bool isUpdated = false;
		long int elapsedExposureTime = 0;
		int globalSampleFrequencyHz = 10;

	};
	
}

#endif