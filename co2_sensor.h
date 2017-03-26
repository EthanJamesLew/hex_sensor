#ifndef CO2_SENSOR_H
#define CO2_SENSOR_H

#include <cmath>
#include <chrono>
#include <thread>
#include "mraa.hpp"

#define         ZERO_POINT_X                 (2.602) 
#define         ZERO_POINT_VOLTAGE           (0.324) 
#define         MAX_POINT_VOLTAGE            (0.265) 
#define         REACTION_VOLTAGE             (0.059)

class CO2_Sensor
{
public:
	CO2_Sensor(int pin_num);
	float readSample();
	float read();
	int readPercentage();

private:
	float CO2Curve[3];
	float dc_gain;
	int sample_times;
	int sample_interval;
	mraa::Aio* pin;
};
#endif
