#include "TemperatureAndHumidity.hpp"



TemperatureAndHumidity::TemperatureAndHumidity(char* portI2C, int addrI2C){
  bus = new I2C(portI2C, addrI2C);
}


int TemperatureAndHumidity::writeI2C(){
  return bus->writeI2C(this->bytesToWrite);
}


void TemperatureAndHumidity::readI2C(unsigned char* global_buffer){
  //unsigned char* buffer =
  bus->readI2C(this->bytesToRead, global_buffer);
  std::cout << "Succeeded reeding from buffer" <<std::endl;

  int nbOfBytes = strlen((char*)global_buffer);
  std::cout << "nbOfBytes " << nbOfBytes << std::endl;

  //seperate the different bits
  this->status = ((uint8_t) (global_buffer[0] & 0xC0) >> 6);
  this->humidity = ((uint16_t) (global_buffer[0] & 0x3f) << 8)  | ((uint16_t) global_buffer[1] );
  this->temperature = (((uint16_t) (global_buffer[2]) << 8)  | ((uint16_t) (global_buffer[3] & 0xFC) )) >>2;
}


unsigned int TemperatureAndHumidity::getStatus(){
  std::cout << "print status bits : " << (unsigned int)this->status << std::endl;
  return (unsigned int)this->status;
}


double TemperatureAndHumidity::getTemp(){
  std::cout << "print tempbitset: " << (unsigned int)this->temperature << std::endl;
  double temp = (( ((unsigned int)this->temperature) / (2^14 - 2)) * 165 ) - 40;
  return temp;
}

double TemperatureAndHumidity::getHum(){

  unsigned int humidity = this->humidity;
  std::cout << "print humidity: " << humidity << std::endl;
  double hum = (humidity /(pow(2,14) - 2)) * 100 ;
  return hum;
}



TemperatureAndHumidity::~TemperatureAndHumidity(){
  delete bus;
}
