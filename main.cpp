#include "co2_sensor.h"
#include <iostream>

int main()
{
	CO2_Sensor co2(0);
	
	while (true)
	{
		std::cout << "C02 ppm: "<< co2.readPercentage() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(333));
	}

	return 0;
}