#ifndef MODULE_CONTROLLERS_H
#define MODULE_CONTROLLERS_H

#include "gui.h"
#include "module_interface.h"

namespace UVO {
	class ControllerESP{
	private:
		UVO::GUI m_screen;
	public:
		ControllerESP();
		~ControllerESP();
		void init(void);
		void update(void);
	};

	

}

#endif