#include "TemperatureAndHumidity.hpp"





//int portI2C;
//int addrI2C;
//int bytesToRead = 4;
//I2C* bus;
//unsigned char buffer[60] = {0};



TemperatureAndHumidity::TemperatureAndHumidity(char* portI2C, int addrI2C){
  bus = new I2C(portI2C, addrI2C);
}

int TemperatureAndHumidity::writeI2C(){
  return bus->writeI2C(this->bytesToWrite);
}

void TemperatureAndHumidity::readI2C(){
  bus->readI2C(this->bytesToRead);
  //save buffer
}

int TemperatureAndHumidity::getStatus(std::bitset<8> first8Bits){
  //std::bitset<8> first8Bits(this->buffer[0]);
  std::bitset<2> status;
  status[0] = first8Bits[0]; //NOTE endre til MOST significant bit??
  status[1] = first8Bits[1];
  return status.to_ulong();

}

double TemperatureAndHumidity::getTemp(){
  std::bitset<32> buffer(this->buffer);

  std::bitset<14> tempBits;

  for (int i=0; i <14; i++){
    tempBits[i] = buffer[i+16]; //NOTE eller motsatt?
  }

  double temp = (( tempBits.to_ulong() / (2^14 - 2)) * 165 ) - 40;

  return temp;
}

double TemperatureAndHumidity::getHum(){
  std::bitset<32> buffer(this->buffer);

  std::bitset<14> humBits;

  for (int i=0; i <14; i++){
    humBits[i] = buffer[i+16]; //NOTE eller motsatt?
  }

  double hum = ((humBits.to_ulong() / (2^14 - 2)) * 165 ) - 40;

  return hum;

}



TemperatureAndHumidity::~TemperatureAndHumidity(){
  delete bus;

}
