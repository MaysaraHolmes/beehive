#include "Pressure.hpp"



Pressure::Pressure(char* portI2C, int addrI2C, unsigned char* global_buffer): Sensor(4,2, portI2C, addrI2C){
  this->readCoefficients(global_buffer);
}

void Pressure::readCoefficients(unsigned char* global_buffer){
  unsigned char buffer[10]={0};
  uint8_t write = (uint8_t)(0x04);
  buffer[0] = write;
  bus->writeI2C(1, buffer);

  bus->readI2C(8, global_buffer);
  int16_t a0coeff = (( (uint16_t) (global_buffer[0]) << 8) | (global_buffer[1]) );
  int16_t b1coeff = (( (uint16_t) (global_buffer[2]) << 8) | (global_buffer[3]));
  int16_t b2coeff = (( (uint16_t) (global_buffer[4]) << 8) | (global_buffer[5]));
  int16_t c12coeff = (( (uint16_t) ((global_buffer[6]) << 8) | (global_buffer[7]))) >> 2;

  this->a0 = (float)a0coeff / 8;
  this->b1 = (float)b1coeff / 8192;
  this->b2 = (float)b2coeff / 16384;
  this->c12 = (float)c12coeff;
  this->c12 /= 4194304.0;
}

int Pressure::writeI2C(){
  return bus->writeI2C(this->bytesToWrite);
}

void Pressure::readI2C(unsigned char* global_buffer){
  bus->readI2C(this->bytesToRead, global_buffer);
  this->pressure = (( (uint16_t)(global_buffer[0]) << 8) | (global_buffer[1]) ) >> 6;
  this->temp = (( (uint16_t)(global_buffer[2]) << 8) | (global_buffer[3]) ) >> 6;
  this->pressureComp = this->a0 + (this->b1 + this->c12 * (this->temp)) * (this->pressure) +
                       (this->b2) * (this->temp);
}

float Pressure::getPressure() {
  return (float)  ((this->pressureComp) * ((115-50)/1023.0F)) + 50.0F;
}

float Pressure::getTemp() {
  return ( ((float)(this->temp) - 498.0F) / (-5.35F)  ) + 25.0F ;
}

Pressure::~Pressure(){
}
