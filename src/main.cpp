#include "main.h"

#if defined(MAIN_CONTROLLER_MODULE)
	UVO::ControllerESP Controller;
#elif defined(LED_DRIVER_MODULE)
	// UVO::ControllerESP Controller;
#elif defined(MOTOR_CONTROLLER_MODULE)
	// UVO::ControllerESP Controller;
#elif defined(DEBUG_MODE)
	#include "communication_test/I2C_communication_test.h"

	#if defined(ARDUINO_RECEIVER)
	UVO_UNIT_TESTS::UNOTransceiver Controller(UVO_UNIT_TESTS::RX_mode);
	#elif defined(ARDUINO_TRANSMITTER)
	UVO_UNIT_TESTS::UNOTransceiver Controller(UVO_UNIT_TESTS::TX_mode);
	#endif

#else
    #error "Define a module: MAIN_CONTROLLER_MODULE, LED_DRIVER_MODULE or MOTOR_CONTROLLER_MODULE"
#endif

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
