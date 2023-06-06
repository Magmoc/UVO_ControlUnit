#ifndef GUISLICE_SCREEN_HPP
#define GUISLICE_SCREEN_HPP

#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#include <string.h>
#include "components/settings.hpp"

namespace UVO_Components {
#define BACKLIGHT_PIN 12

namespace GUISlice {
	#include "components/GUI/GUISliceBuilder_GSLC.hpp"

	struct s_screenState {
		typedef std::vector<gslc_tsElemRef*> glsc_ElemRefVec;

		const glsc_ElemRefVec SETUP_page_elem_arr = {
			m_pElem_SETUP_Intensity_255nm,
			m_pElem_SETUP_Intensity_275nm,
			m_pElem_SETUP_Intensity_285nm,
			m_pElem_SETUP_Intensity_395nm,
			m_pElem_SETUP_Hours,
			m_pElem_SETUP_Minutes,
			m_pElem_SETUP_Seconds,
			m_pElem_SETUP_MotorIntensity,
			m_pElem_SETUP_Dosis_255nm,
			m_pElem_SETUP_Dosis_275nm,
			m_pElem_SETUP_Dosis_285nm,
			m_pElem_SETUP_Dosis_395nm,
			};

		const std::vector<glsc_ElemRefVec> page_vec = {SETUP_page_elem_arr};

		int current_elem_idx = 0; // TODO should add box around object
		bool elem_is_selected = false; // TODO if true: should change background color of thing
		int current_page_idx = 0;

		// TODO HERE or should button handler fix this?
		
		volatile bool button_up_pressed;
		volatile bool button_down_pressed;
		
	};

	class Screen{
	private:
		// TFT_eSPI m_tft = TFT_eSPI();
		// TFT_eSprite m_screen = TFT_eSprite(&m_tft);	
		// TFT_eSprite m_popupSprite = TFT_eSprite(&m_tft); 

		// const uint16_t UVO_BLACK = m_tft.color565(0, 0, 5);
		// const uint16_t UVO_DARK_BLUE = m_tft.color565(59, 51, 85);
		// const uint16_t UVO_PURPLE = m_tft.color565(93, 93, 129);
		// const uint16_t UVO_LIGHT_BLUE = m_tft.color565(191, 205, 224);
		// const uint16_t UVO_WHITE = m_tft.color565(254, 252, 253);

		const int m_TFT_WIDTH = 480;
		const int m_TFT_HEIGHT = 320;

		// Need to swap the width and height due to the rotation of the tft screen
		// Probably a bug in the system, or because I did something wrong
		const int m_SPRITE_WIDTH = m_TFT_HEIGHT;
		const int m_SPRITE_HEIGHT = m_TFT_WIDTH;

		bool m_updateFrame;
		u_int8_t m_Count = 0;

		void writeFrame(void);

		void setBackground(TFT_eSprite& sprite);
		void setBackgroundText(TFT_eSPI& sprite);
		void test(void);

		void GUISliceInit(void);

		void displaySetupSettings(void);
		void displayIntensity(gslc_tsElemRef* elem, uint8_t intensity);
		void displayTime(gslc_tsElemRef* t_hour, gslc_tsElemRef* t_minutes, gslc_tsElemRef* t_seconds, time_t t_displayTime);

		int uint8_to_percentage(uint8_t value);

		s_setupSettings* m_setupSettings;


		public:
			Screen(s_setupSettings* t_Settings);
			Screen(void);
			~Screen();
			
			// Both with and without setupSettings so that you can restart the module without having to change the settings
			void init(void);
			void init(s_setupSettings* t_initSettings);
			
			void update(void);
			void setSetupSettings(s_setupSettings* t_Settings);

	};
}
}
#endif