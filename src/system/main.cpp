//#include "I2C.hpp"
#include "TemperatureAndHumidity.hpp"
#include <bitset>
#include <iostream>

#define I2C_PORT1 (char*)"/dev/i2c-1"
#define I2C_PORT2 (char*)"/dev/i2c-3"
#define ADDR_TEMP_AND_HUM 0X27
//#define ADDR_ADC 0x50
/* NOTE use this instead?
namespace {
   const char* I2C_PORT1 = (char*)"/dev/i2c-1";
   const char* I2C_PORT2 = (char*)"/dev/i2c-3";
};
*/

unsigned char global_buffer[4]={0};
int main(){

  TemperatureAndHumidity th1(I2C_PORT1, ADDR_TEMP_AND_HUM);
  int i = th1.writeI2C();
  th1.readI2C(global_buffer);
  std::cout << "status: " << th1.getStatus() << std::endl;
  std::cout << "temp: " << th1.getTemp() << std::endl;
  std::cout << "humidity: " << th1.getHum() << std::endl;
  

  //std::bitset<8> b;
  //b[7] = 0;
  //b[6] = 1;
  //b[5] = 0;
  //b[4] = 1;
  //b[3] = 0;
  //b[2] = 1;
  //b[1] = 0;
  //b[0] = 0;
  //std::cout<< "testing bitset: " << b << std::endl;

  //std::cout << "unsinged int: " << th1.getStatus(b) << std::endl;



  printf("The program is running %d\n", i);


}
