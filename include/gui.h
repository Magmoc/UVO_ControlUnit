#ifndef GUI_H
#define GUI_H

#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#define BACKLIGHT_PIN 12

class GUI{
private:
	TFT_eSPI _tft = TFT_eSPI();
	TFT_eSprite spr_main = TFT_eSprite(&_tft);
	TFT_eSprite spr_popup = TFT_eSprite(&_tft);

	void write_frame(void);

	bool update_frame;
public:
	GUI(void);
	~GUI();
	void drawArrayJpeg(TFT_eSPI layer, const uint8_t arrayname[], uint32_t array_size, int xpos, int ypos);
	void jpegInfo();
	void renderJPEGonLayer(TFT_eSPI layer, int xpos, int ypos);
	void init(void);
	void update(void);
};

#endif