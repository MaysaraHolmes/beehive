
//#include "TemperatureAndHumidity.hpp"
#include "ReadI2CDevices.hpp"
#include "Sensor.hpp"
#include <iostream>


//#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <string>
//#include <vector>
#include <thread>
//#include <mutex>
#include "CppTimer.h"
#include "Fan.hpp"

#define I2C_PORT1 (char*)"/dev/i2c-1"//remove
#define I2C_PORT2 (char*)"/dev/i2c-3"//remove
#define ADDR_TEMP_AND_HUM 0X27//remove
//#define ADDR_ADC 0x50
/* NOTE use this instead?
namespace {
   const char* I2C_PORT1 = (char*)"/dev/i2c-1";
   const char* I2C_PORT2 = (char*)"/dev/i2c-3";
};
*/




unsigned char global_buffer[4]={0};
int main(int argc, const char* argv[] ){



//NOTE:Inside thread:
  ReadI2CDevices* r = new ReadI2CDevices();
  r->writeAll();
  //r.readAll();

  std::thread sensorThread(&ReadI2CDevices::readAll, r);
  sensorThread.join();
  delete r;

  DemoTimer1 demoTimer1;
	demoTimer1.start(25000000000); //every 25sec

  do {
		sleep(1);
	} while (1);




}
