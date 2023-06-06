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

		const glsc_ElemRefVec SETUP_page_selectable_items = {
			m_pElem_SETUP_Intensity_255nm,
			m_pElem_SETUP_Intensity_275nm,
			m_pElem_SETUP_Intensity_285nm,
			m_pElem_SETUP_Intensity_395nm,
			m_pElem_SETUP_Hours,
			m_pElem_SETUP_Minutes,
			m_pElem_SETUP_Seconds,
			m_pElem_SETUP_MotorIntensity,
			};

		const std::vector<glsc_ElemRefVec> page_vec = {SETUP_page_selectable_items};
		int current_page_idx = 0;

		int current_elem_idx = 0; // TODO should add box around object
		bool elem_is_selected = false; // TODO if true: should change background color of thing

		// TODO HERE or should button handler fix this?
		
		volatile bool button_up_pressed;
		volatile bool button_down_pressed;
		
	};

	class Screen{
	private:
		// TFT_eSPI m_tft = TFT_eSPI();
		// TFT_eSprite m_screen = TFT_eSprite(&m_tft);	
		// TFT_eSprite m_popupSprite = TFT_eSprite(&m_tft); 

		const gslc_tsColor UVO_BLACK = {0, 0, 5};
		const gslc_tsColor UVO_DARK_BLUE = {59, 51, 85};
		const gslc_tsColor UVO_PURPLE = {93, 93, 129};
		const gslc_tsColor UVO_LIGHT_BLUE = {191, 205, 224};
		const gslc_tsColor UVO_WHITE = {254, 252, 253};

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

		void displaySelected(gslc_tsElemRef* t_pElem);

		void displaySetupSettings(void);
		void displayIntensity(gslc_tsElemRef* t_pElem, uint8_t intensity);
		void displayTime(gslc_tsElemRef* t_hour, gslc_tsElemRef* t_minutes, gslc_tsElemRef* t_seconds, time_t t_displayTime);

		int uint8_to_percentage(uint8_t value);

		s_setupSettings* m_setupSettingsPointer;


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