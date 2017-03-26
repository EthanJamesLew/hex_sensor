#include "co2_sensor.h"
#include "mraa.hpp"
#include "humid_htu21df.h"
#include <iostream>

int main()
{
	CO2_Sensor co2(0);
	mraa::I2c* i2c = new mraa::I2c(0);
	Humid_HTU21DF hum(i2c);
	hum.begin();

	while (true)
	{
		std::cout << "C02 ppm: "<< co2.readPercentage() << std::endl;
		std::cout << "HUM: " << hum.readTemperature() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(333));
	}

	return 0;
}