#include "module_controllers.h"

namespace UVO {
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

}