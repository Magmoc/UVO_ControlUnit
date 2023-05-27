#include "components/communication/main_controller_communication_interface.hpp"

namespace UVO_MainController {

MainCommunicationInterface::MainCommunicationInterface(int t_I2C_address){

}

MainCommunicationInterface::~MainCommunicationInterface(){

}


//TODO fix
// Use I2C interface and SPI interface for default communication
// that way you can later switch them very easily if you need a differnet protocol
// then define communication interfaces per module with the different types of functions
// so for example
// 		request sensor data
//		send sensor data
//		set pwm
// 		receive pwm signal
// 		

//bool MainCommunicationInterface::requestSensorData(Sensor sensor){
// send address
// request data
// save data in byte array
// convert to proper data type
// store data in sensor
// }

//bool MainCommunicationInterface::setPWMDutyCycle(Driver driver, int pwm){

// }

}
