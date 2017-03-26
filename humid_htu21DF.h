#ifndef HUMID_HTU21DF_H
#define HUMID_HTU21DF_H

#include "mraa.h"
#include <chrono>
#include <thread>
#include <iostream>

#define HTU21DF_I2CADDR       0x40
#define HTU21DF_READTEMP      0xE3
#define HTU21DF_READHUM       0xE5
#define HTU21DF_WRITEREG       0xE6
#define HTU21DF_READREG       0xE7
#define HTU21DF_RESET		0xFE

class Humid_HTU21DF {
public:
	Humid_HTU21DF(mraa::I2c* i);
	bool begin(void);
	float readTemperature(void);
	float readHumidity(void);
	void reset(void);
private:
	mraa::I2c* i2c;
	bool readData(void);
	float humidity, temp;
};

Humid_HTU21DF::Humid_HTU21DF(): i2c(i)
{}

bool Humid_HTU21DF::begin(void)
{
	i2c->address(HTU21DF_I2CADDR);
	i2c->write(HTU21DF_READREG, 1);
	return (i2c->read() == 0x2);
}

float Humid_HTU21DF::readTemperature(void)
{
	i2c->address(HTU21DF_I2CADDR);
	i2c->write(HTU21DF_READTEMP, 1);
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

	uint8_t* dat = new uint8_t(3);
	i2c->read(dat, 3);
	std::cout << dat[0] << dat[1] << dat[3] << std::endl;
	return 1.0f;
}

float Humid_HTU21DF::readHumidity(void)
{
	return 1.0f;
}

void Humid_HTU21DF::reset(void)
{
	i2c->address(HTU21DF_I2CADDR);
	i2c->write(HTU21DF_RESET, 1);
	std::this_thread::sleep_for(std::chrono::milliseconds(15));
}

#endif