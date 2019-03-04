//#include "I2C.hpp"
#include "TemperatureAndHumidity.hpp"//remove
#include "ReadI2CDevices.hpp"
#include "Sensor.hpp"
//#include <bitset>
#include <iostream>


//#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <string>
//#include <vector>
#include <thread>
//#include <mutex>

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

#include "CppTimer.h"
#include <unistd.h>

unsigned char global_buffer[4]={0};
int main(){


  TemperatureAndHumidity th1(I2C_PORT1, ADDR_TEMP_AND_HUM);
  int i = th1.writeI2C();
  th1.readI2C(global_buffer);
  std::cout << "status: " << th1.getStatus() << std::endl;
  std::cout << "temp: " << th1.getTemp() << std::endl;
  std::cout << "humidity: " << th1.getHum() << std::endl;
  std::cout << "\n\n\n" << std::endl;


//NOTE:Inside thread:
  ReadI2CDevices* r = new ReadI2CDevices();
  r->writeAll();
  //r.readAll();

  std::thread sensorThread(&ReadI2CDevices::readAll, r);
  sensorThread.join();
  delete r;

  /*
  1.start thread readI2CDevices
      - wait til interruptet?
      - read all the devices on the two buses
      - send the reading somewhere
  */

  /*
  2.Start Alarm thread
      - create object of the alarm class
      - listen to pin/sleep
      - pin interrupted => wake readI2CDevices-thread
      - sleep/wait for new interrupt on the pin
  */




  printf("The program is running %d\n", i);


}
