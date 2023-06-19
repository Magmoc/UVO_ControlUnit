// **********************************************
// 		EE3L11: Bachelor Graduation Project
//		GROUP M: UVC SEED STERILIZATION
//		SUBGROUP: SOFTWARE AND CONTROL
// 		MEMBERS: Erman Ergul, Erik van Weelderen
// 		
// 		BY ERIK VAN WEELDEREN
// 		DATE: 16-6-2023
// **********************************************

#ifndef _MAIN_HPP
#define _MAIN_HPP

#include <Arduino.h>

void setup();
void loop();

#if defined(MAIN_CONTROLLER_MODULE)
	#include "modules/control_module/main_controller.hpp"
	UVO_MainController::MainController Controller;
#else
	#error "Define a module: MAIN_CONTROLLER_MODULE"
#endif

#endif