#ifndef GUI_H
#define GUI_H

#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library

class Gui{
private:
	TFT_eSPI _tft = TFT_eSPI();
public:
	Gui(void);
	~Gui();
	void init(void);
	void test(void);
	void update(void);
};

#endif