#include "main.h"

#if defined(DEBUG_MODE_TEST)
	#include "communication_test/I2C_communication_test.h"

	#if defined(MASTER_MODE)
		UVO_UNIT_TESTS::UNOTransceiver Controller(UVO_UNIT_TESTS::MASTER_OPERATION_MODE, UVO_UNIT_TESTS::MASTER_ADDRESS);
	#elif defined(SLAVE_MODE)
		UVO_UNIT_TESTS::UNOTransceiver Controller(UVO_UNIT_TESTS::SLAVE_OPERATION_MODE, UVO_UNIT_TESTS::SLAVE_ADDRESS);
	#else
		#error "Please specifiy either MASTER_MODE or SLAVE_MODE"
	#endif

#else
	#include "module_controllers.h"

	#if defined(MAIN_CONTROLLER_MODULE)
		UVO::ControllerESP Controller;
	#elif defined(LED_DRIVER_MODULE)
		UVO::ControllerESP Controller;
	#elif defined(MOTOR_CONTROLLER_MODULE)
		UVO::ControllerESP Controller;

	#else
		#error "Define a module: MAIN_CONTROLLER_MODULE, LED_DRIVER_MODULE or MOTOR_CONTROLLER_MODULE"
	#endif

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
