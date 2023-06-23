// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergül, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

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
	//TODO MAKE STRUCT WITH elem id, whether it is editable, and pointer to what it changes, and which function to use for changing the value
	//TODO STRUCT OF A PAGE
	//	- number of selectable elems
	//	- editable elems
	//	- refs to all elems
	enum Pages {setupPage, monitorPage};

	struct s_screenState {
		
		#define SETUP_PAGE_SELECTABLE_ITEMS_NUM 8
		#define MONITOR_PAGE_SELECTABLE_ITEMS_NUM 2
		
		const int SETUP_page_selectable_items_size = SETUP_PAGE_SELECTABLE_ITEMS_NUM;
		const int MONITOR_page_selectable_items_size = MONITOR_PAGE_SELECTABLE_ITEMS_NUM;
		gslc_tsElemRef* SETUP_page_selectable_items[SETUP_PAGE_SELECTABLE_ITEMS_NUM];
		gslc_tsElemRef* MONITOR_page_selectable_items[MONITOR_PAGE_SELECTABLE_ITEMS_NUM];

		// Must call this after initializing GSLC
		void init(void){
			init_SETUP_sel_array();
			init_MONITOR_sel_array();
		}

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

		void init_MONITOR_sel_array(void){
			MONITOR_page_selectable_items[0] = m_pElem_MONITOR_Pause;
			MONITOR_page_selectable_items[1] = m_pElem_MONITOR_Stop;
		}

		gslc_tsElemRef** page_vec[2] = {SETUP_page_selectable_items, MONITOR_page_selectable_items};
		int page_vec_array_sizes[2] = {SETUP_PAGE_SELECTABLE_ITEMS_NUM, MONITOR_PAGE_SELECTABLE_ITEMS_NUM};
		
		//TODO update it not to use idx but rather enum selected page
		Pages current_page = setupPage;
		bool update_current_page = false;

		int current_elem_idx = 0;
		
		//TODO better name
		bool elem_is_editing = false;


		gslc_tsElemRef* getCurrentlySelectedElem(void){
			return page_vec[(int) current_page][current_elem_idx];
		}

		uint16_t getCurrentlySelectedElemID(void){
			return page_vec[(int) current_page][current_elem_idx]->pElem->nId;
		}

		//TODO FIX DATA STRUCTURE
		uint16_t getCurrentPageID(void){
			switch (current_page){
			case setupPage:
				return E_PG_SETUP;
				break;
			case monitorPage:
				return E_PG_MONITOR;
				break;
			default:
				return E_PG_ERROR;
			}
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
		void beginEditSelectedElem(void);
		void endEditSelectedElem(void);
		void toggleEditSelectedElem(void);

		bool isEditingElement(void);
		uint16_t getCurrentElementID(void);

		//TODO Fix this
		// void selectPage(page t_page);

		void selectSetupPage(void);
		void selectMonitorPage(void);

	private:
		s_setupSettings* m_referenceSetupSettingsPointer;
		s_setupSettings m_currentlyDisplayedSetupSettings;

		s_screenState m_screenState;

		const gslc_tsColor UVO_BLACK = {0, 0, 5};
		const gslc_tsColor UVO_DARK_BLUE = {59, 51, 85};
		const gslc_tsColor UVO_PURPLE = {93, 93, 129};
		const gslc_tsColor UVO_LIGHT_BLUE = {191, 205, 224};
		const gslc_tsColor UVO_WHITE = {254, 252, 253};

		bool m_updateFrame;

		void writeFrame(void);

		void setBackground(TFT_eSprite& sprite);
		void setBackgroundText(TFT_eSPI& sprite);
		void test(void);

		void GUISliceInit(void);

		void setColorFrame(gslc_tsElemRef* t_pElem, gslc_tsColor t_colFrame);
		void setColorFill(gslc_tsElemRef* t_pElem, gslc_tsColor t_colFill);

		//TODO better name
		void resetElemOptions(gslc_tsElemRef* t_pElem);


		// TODO rename the setSelected and updatedSelected. It is quite unclear.
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