#ifndef MAIN_CONTROLLER_COMMUNICATION_INTERFACE_H
#define MAIN_CONTROLLER_COMMUNICATION_INTERFACE_H

#include <Wire.h>

namespace UVO_MainController {

class MainCommunicationInterface
{
private:
	/* data */
public:
	MainCommunicationInterface(int t_I2C_address);
	MainCommunicationInterface(int t_I2C_address, int t_SDA_pin, int t_SCL_pin);
	~MainCommunicationInterface();
};

}

#endif