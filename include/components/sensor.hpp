#ifndef SENSOR_HPP
#define SENSOR_HPP

namespace UVO_Components {

class Sensor
{
private:
	union address
	{
		int I2C_address;
		int SPI_address;
	};
	
		
public:
	Sensor(/* args */);
	~Sensor();
};

}

#endif