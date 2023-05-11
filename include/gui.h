#ifndef GUI_H
#define GUI_H

#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#define BACKLIGHT_PIN 12

class GUI{
private:
	TFT_eSPI _tft = TFT_eSPI();
	void write_frame(void);

	bool update_frame;
public:
	GUI(void);
	~GUI();
	void init(void);
	void update(void);
};

#endif