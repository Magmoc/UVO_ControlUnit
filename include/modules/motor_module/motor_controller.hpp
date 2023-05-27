#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

// #include "components/communication_interface.hpp"

namespace UVO_MotorController {
	class MotorController{
	private:
	public:
		MotorController();
		~MotorController();
		void init(void);
		void update(void);
	};

}

#endif