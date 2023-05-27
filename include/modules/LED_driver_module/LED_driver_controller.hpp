#ifndef LED_DRIVER_CONTROLLER_HPP
#define LED_DRIVER_CONTROLLER_HPP

// #include "components/I2C_interface.hpp"

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