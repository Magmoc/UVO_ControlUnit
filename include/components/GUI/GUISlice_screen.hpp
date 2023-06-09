#ifndef _GUISLICE_SCREEN_HPP
#define _GUISLICE_SCREEN_HPP

#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#include <string.h>
#include "components/settings.hpp"

namespace UVO_Components {
#define BACKLIGHT_PIN 12

namespace GUISlice {
	#include "components/GUI/GUISliceBuilder_GSLC.hpp"

	//TODO make screenstate into a class
	struct s_screenState {
		
		#define SETUP_PAGE_SELECTABLE_ITEMS_NUM 8
		const int SETUP_page_selectable_items_size = SETUP_PAGE_SELECTABLE_ITEMS_NUM;
		gslc_tsElemRef* SETUP_page_selectable_items[SETUP_PAGE_SELECTABLE_ITEMS_NUM];

		// Must call this after initializing GSLC
		void init_SETUP_sel_array(void){
			SETUP_page_selectable_items[0] = m_pElem_SETUP_Intensity_255nm;
			SETUP_page_selectable_items[1] = m_pElem_SETUP_Intensity_275nm;
			SETUP_page_selectable_items[2] = m_pElem_SETUP_Intensity_285nm;
			SETUP_page_selectable_items[3] = m_pElem_SETUP_Intensity_395nm;
			SETUP_page_selectable_items[4] = m_pElem_SETUP_Hours;
			SETUP_page_selectable_items[5] = m_pElem_SETUP_Minutes;
			SETUP_page_selectable_items[6] = m_pElem_SETUP_Seconds;
			SETUP_page_selectable_items[7] = m_pElem_SETUP_MotorIntensity;
		}

		gslc_tsElemRef** page_vec[1] = {SETUP_page_selectable_items};
		int page_vec_array_sizes[1] = {SETUP_PAGE_SELECTABLE_ITEMS_NUM};
		
		int current_page_idx = 0;
		bool update_current_page = false;

		int current_elem_idx = 0;
		
		//TODO better name
		bool elem_is_editing = false;

		// TODO HERE or should button handler fix this?
		
		volatile bool button_up_pressed;
		volatile bool button_down_pressed;
		
		gslc_tsElemRef* getCurrentlySelectedElem(void){
			return page_vec[current_page_idx][current_elem_idx];
		}

	};

	class Screen{
	public:
		Screen(s_setupSettings* t_Settings);
		Screen(void);
		~Screen();
		
		// Both with and without setupSettings so that you can restart the module without having to change the settings
		void init(void);
		void init(s_setupSettings* t_initSettings);
		
		void update(void);
		void setSetupSettings(s_setupSettings* t_Settings);
		
		void selectPreviousElem(void);
		void selectNextElem(void);
		void toggleEditSelectedElem(void);
		bool isEditingElement(void);

	private:
		s_setupSettings* m_referenceSetupSettingsPointer;
		s_setupSettings m_currentlyDisplayedSetupSettings;

		s_screenState m_screenState;
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

		void setColorFrame(gslc_tsElemRef* t_pElem, gslc_tsColor t_colFrame);
		void setColorFill(gslc_tsElemRef* t_pElem, gslc_tsColor t_colFill);
		

		//TODO better name
		void resetElemOptions(gslc_tsElemRef* t_pElem);


		// TODO rename the setSelected and updatedSelected. Is quite unclear whoopsie.
		void setSelectedElem(gslc_tsElemRef* t_pElem);
		void setSelectedElem(int t_index);
		void updateSelectedElem(int t_newSelectedIdx);

		void displayAsSelected(gslc_tsElemRef* t_pElem);
		void displayAsEditing(gslc_tsElemRef* t_pElem);

		bool hasFillEnabled(gslc_tsElemRef* t_pElem);


		void displayInteger(gslc_tsElemRef* t_pElem, uint8_t t_value);


		void displaySetupSettings(s_setupSettings* t_new);
		void displayIntensity(gslc_tsElemRef* t_pElem, uint8_t intensity);
		void displayTime(gslc_tsElemRef* t_hour, gslc_tsElemRef* t_minutes, gslc_tsElemRef* t_seconds, time_t t_displayTime);

		int uint8_to_percentage(uint8_t value);
		template<typename T> std::optional<int> getIndex(T* t_vec, int t_size, T t_elem);
	};
}
}
#endif