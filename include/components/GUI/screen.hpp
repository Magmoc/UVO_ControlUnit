#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#include <string.h>

#define BACKLIGHT_PIN 12

namespace UVO_Components {
namespace Screen {

	class Screen{
	private:
		TFT_eSPI m_tft = TFT_eSPI();
		TFT_eSprite m_screen = TFT_eSprite(&m_tft);	
		// TFT_eSprite m_popupSprite = TFT_eSprite(&m_tft); 

		const uint16_t UVO_BLACK = m_tft.color565(0, 0, 5);
		const uint16_t UVO_DARK_BLUE = m_tft.color565(59, 51, 85);
		const uint16_t UVO_PURPLE = m_tft.color565(93, 93, 129);
		const uint16_t UVO_LIGHT_BLUE = m_tft.color565(191, 205, 224);
		const uint16_t UVO_WHITE = m_tft.color565(254, 252, 253);

		const int m_TFT_WIDTH = 480;
		const int m_TFT_HEIGHT = 320;

		// Need to swap the width and height due to the rotation of the tft screen
		// Probably a bug in the system, or because I did something wrong
		const int m_SPRITE_WIDTH = m_TFT_HEIGHT;
		const int m_SPRITE_HEIGHT = m_TFT_WIDTH;

		bool m_updateFrame;

		void writeFrame(void);

		void setBackground(TFT_eSprite& sprite);
		void setBackgroundText(TFT_eSPI& sprite);
		void test(void);

	public:
		Screen(void);
		~Screen();
		void init(void);
		void update(void);

	};
}
}
#endif