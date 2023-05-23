#ifndef UNO_CONTROLLERS_H
#define UNO_CONTROLLERS_H

#include "module_interface.h"
#include <random>

namespace UVO_UNIT_TESTS {
	
	enum OperationMode {TX_mode, RX_mode};
	
	class UNOTransceiver
	{
	private:
		OperationMode m_operationMode;
	public:
		UNOTransceiver(OperationMode t_operationMode);
		void init();
		void update();
	};
}

#endif