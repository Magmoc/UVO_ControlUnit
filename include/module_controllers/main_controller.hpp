#ifndef MAIN_CONTROLLER_HPP
#define MAIN_CONTROLLER_HPP

#include "components/gui.hpp"
#include "components/communication_interface.hpp"

#define USER_SETUP_LOADED
#define ST7796_DRIVER

#define TFT_RST 32
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS 4
#define TFT_DC 2
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT
#define SPI_FREQUENCY 27000000

namespace UVO_MainController {

class MainController{
private:
	UVO_Components::GUI m_screen;
public:
	MainController();
	~MainController();
	void init(void);
	void update(void);
};

}

#endif