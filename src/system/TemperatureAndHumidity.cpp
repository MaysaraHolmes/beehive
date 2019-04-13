#include "TemperatureAndHumidity.hpp"


TemperatureAndHumidity::TemperatureAndHumidity(char* portI2C, int addrI2C): Sensor(4,2, portI2C, addrI2C){
}

int TemperatureAndHumidity::writeI2C(){
  return bus->writeI2C(this->bytesToWrite);
}

void TemperatureAndHumidity::readI2C(unsigned char* global_buffer){
  bus->readI2C(this->bytesToRead, global_buffer);
  int nbOfBytes = strlen((char*)global_buffer);

  this->status = ((uint8_t) (global_buffer[0] & 0xC0) >> 6);
  this->humidity = ((uint16_t) (global_buffer[0] & 0x3f) << 8)  | ((uint16_t) global_buffer[1] );
  this->temperature = (((uint16_t) (global_buffer[2]) << 8)  | ((uint16_t) (global_buffer[3] & 0xFC) )) >>2;
}

unsigned int TemperatureAndHumidity::getStatus() {
  return (unsigned int)this->status;
}

double TemperatureAndHumidity::getTemp() {
  return (double)(( ((unsigned int)this->temperature) / (pow(2,14) - 2)) * 165 ) - 40;
}

double TemperatureAndHumidity::getHum() {
  return (double)(this->humidity /(pow(2,14) - 2)) * 100 ;
}

TemperatureAndHumidity::~TemperatureAndHumidity(){
}
