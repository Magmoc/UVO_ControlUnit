#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>

void setup();
void loop();

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
	#if defined(MAIN_CONTROLLER_MODULE)
		#include "module_controllers/main_controller.h"
		UVO_MainController::MainController Controller;
	#elif defined(LED_DRIVER_MODULE)
		#include "module_controllers/LED_driver_controller.h"
		UVO::MainController Controller;
	#elif defined(MOTOR_CONTROLLER_MODULE)
		#include "module_controllers/motor_controller.h"
		UVO::MainController Controller;

	#else
		#error "Define a module: MAIN_CONTROLLER_MODULE, LED_DRIVER_MODULE or MOTOR_CONTROLLER_MODULE"
	#endif

#endif


#endif