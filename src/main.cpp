#include <SPI.h>
#include "main.h"




class ControllerESP{
private:
	GUI m_screen;
public:
	ControllerESP();
	~ControllerESP();
	void init(void);
	void update(void);
};

ControllerESP::ControllerESP(){

}

ControllerESP::~ControllerESP(){

}

void ControllerESP::init(void){
	m_screen.init();
}

void ControllerESP::update(void){
	m_screen.update();
}


ControllerESP Controller;

void setup() {
	Serial.begin(9600);
	Controller.init();
}

void loop(void) {
	Controller.update();
	// Screen.m_tft.fillScreen(TFT_GREEN);

	// Serial.println("test");
	// Screen.update();
	// digitalWrite(13, LOW);
	// digitalWrite(15, HIGH);
}
