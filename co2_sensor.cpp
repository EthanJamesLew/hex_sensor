#include "co2_sensor.h"

CO2_Sensor::CO2_Sensor(int pin_num) : sample_times(10), sample_interval(50), dc_gain(8.5)
{
	float CO2Curve[3] = { ZERO_POINT_X, ZERO_POINT_VOLTAGE, (REACTION_VOLTAGE / (2.602 - 4)) };
	pin = new mraa::Aio(pin_num);
	if (!pin);
	//Raise Error
}

float CO2_Sensor::readSample()
{
	int i;
	float v = 0.0f;

	for (i = 0; i < sample_times; i++)
	{
		v += pin->readFloat();
		std::this_thread::sleep_for(std::chrono::milliseconds(sample_interval));

	}
	v = (v / sample_times) * 5.0f / 1024.0f;

	return v;
}

float CO2_Sensor::read()
{
	return pin->readFloat();
}

int CO2_Sensor::readPercentage()
{
	float volts = readSample() / dc_gain;
	if (volts > ZERO_POINT_VOLTAGE || volts < MAX_POINT_VOLTAGE) {
		return -1;
	}
	else {
		return pow(10, (volts - CO2Curve[1]) / CO2Curve[2] + CO2Curve[0]);
		volts = 0;
	}

}