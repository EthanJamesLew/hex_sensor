#include "humid_htu21DF.h"

Humid_HTU21DF::Humid_HTU21DF(mraa::I2c* i) : i2c(i),
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
