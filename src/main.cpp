#include <SPI.h>
#include "main.h"




class ControllerESP{
private:
	GUI _Screen;
public:
	ControllerESP(/* args */);
	~ControllerESP();
	void init(void);
	void update(void);
};

ControllerESP::ControllerESP(/* args */){

}

ControllerESP::~ControllerESP(){

}

void ControllerESP::init(void){
	_Screen.init();
}

void ControllerESP::update(void){
	_Screen.update();
}


ControllerESP Controller;

void setup() {
	// Use serial port
	Serial.begin(9600);
	Controller.init();
}

//------------------------------------------------------------------------------------------

void loop(void) {
	Controller.update();
	// Screen._tft.fillScreen(TFT_GREEN);

	// Serial.println("test");
	// Screen.update();
	// digitalWrite(13, LOW);
	// digitalWrite(15, HIGH);
}
