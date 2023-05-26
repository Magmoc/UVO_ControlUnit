#ifndef LED_DRIVER_CONTROLLER_H
#define LED_DRIVER_CONTROLLER_H

#include "module_interface.h"

namespace UVO_LEDDriverController {
	class LEDDriverController{
	private:
	public:
		LEDDriverController();
		~LEDDriverController();
		void init(void);
		void update(void);
	};

}

#endif