#ifndef MAIN_CONTROLLER_HPP
#define MAIN_CONTROLLER_HPP

#include "main_controller_defines.hpp"
#include "components/gui.hpp"
// #include "components/communication_interface.hpp"

namespace UVO_MainController {

class MainController{
private:
	UVO_Components::GUI m_screen;
public:
	MainController();
	~MainController();
	void init(void);
	void update(void);
};

}

#endif