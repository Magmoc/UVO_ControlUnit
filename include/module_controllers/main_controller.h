#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include "gui.h"
#include "module_interface.h"

// TODO(MAKE FOLDER WITH ALL THE MODULE CONTROLLER FILES. SO ESPCONTROLLER.CPP / MOTORCONTROLLER.CPP ETC ETC. THAT WAY GUI DOES NOT HAVE TO BE INCLUDED IN EVRY THING)

namespace UVO {
	class MainController{
	private:
		UVO::GUI m_screen;
	public:
		MainController();
		~MainController();
		void init(void);
		void update(void);
	};

	

}

#endif