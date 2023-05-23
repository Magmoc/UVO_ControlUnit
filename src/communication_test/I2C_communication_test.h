#ifndef UNO_CONTROLLERS_H
#define UNO_CONTROLLERS_H

#include "module_interface.h"
// #include <random.h>


namespace UVO_UNIT_TESTS {
	const int MASTER_ADDRESS = 40;
	const int SLAVE_ADDRESS = 50;
	
	enum OperationMode {SLAVE_OPERATION_MODE, MASTER_OPERATION_MODE};
	
	class UNOTransceiver
	{
	private:
		OperationMode m_operationMode;
		int m_I2C_address;
		void masterInit(void);
		void slaveInit(void);

		void masterUpdate(void);
		void slaveUpdate(void);

	public:
		UNOTransceiver(OperationMode t_operationMode, int t_I2C_address);
		void init();
		void update();
	};

	void requestEvent(void);

}

#endif