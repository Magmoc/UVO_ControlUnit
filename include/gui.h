#ifndef GUI_H
#define GUI_H

#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#define BACKLIGHT_PIN 12

namespace UVO {
		
	class GUI{
	private:
		TFT_eSPI m_tft = TFT_eSPI();

		// BE CAREFULL ABOUT USING TOO MANY SPRITES / TOO BIG SPRITES / TOO MUCH MEMORY
		// THINGS WILL FAIL
		TFT_eSprite m_mainSprite = TFT_eSprite(&m_tft);
		TFT_eSprite m_popupSprite = TFT_eSprite(&m_tft);

		bool m_updateFrame;

		void writeFrame(void);

	public:
		GUI(void);
		~GUI();
		void init(void);
		void update(void);
	};

}
#endif