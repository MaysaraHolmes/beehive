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


  if (nbOfBytes >=4 ){
    //unsigned char bytes[4];
    //for (int i=0; i<4; i++){
    //  bytes[i] = global_buffer[i];   //NOTE CHange the order?
    //}

    //NOTE get only the four bytes we need, save local
    unsigned int i = *global_buffer;
    //4bytes of the global_buffer rigth and left shift
    this->i = i;

    std::cout << "working " << std::endl;
    //std::bitset<32> bits(*bytes);
    //std::cout << "is it still running? " << std::endl;
    //this->bitsetI2C = bits;
    //std::cout << "print bitset: " << bits << std::endl;

  std::cout << "size of buffer: " << nbOfBytes << std::endl;
  std::cout << "print buffer: " << global_buffer << std::endl;
  }
}

int TemperatureAndHumidity::getStatus(){
  //std::bitset<2> status;
  //status[0] = this->bitsetI2C[0]; //NOTE endre til MOST significant bit??
  //status[1] = this->bitsetI2C[1];
  unsigned int status = (this->i) >>(32-2);

  return status;

}

double TemperatureAndHumidity::getTemp(){
  /*
  std::bitset<14> tempBits;

  for (int i=0; i <14; i++){
    tempBits[i] = this->bitsetI2C[i+16]; //NOTE eller motsatt?
  }
  */
  unsigned int tempBits = ((this->i)<<16) >>(32-14);
  //NOTE convert to signed int?
  double temp = (( tempBits / (2^14 - 2)) * 165 ) - 40;

  return temp;
}

double TemperatureAndHumidity::getHum(){
  /*
  std::bitset<14> humBits;

  for (int i=0; i <14; i++){
    humBits[i] = this->bitsetI2C[i+16]; //NOTE eller motsatt?
  }
  */
  unsigned int humBits = ((this->i)<<2) >>(32-14);
  //NOTE convert to signed int?
  double hum = ((humBits / (2^14 - 2)) * 100 );
  return hum;



}



TemperatureAndHumidity::~TemperatureAndHumidity(){
  delete bus;
}
