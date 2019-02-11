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
    unsigned char bytes[4];
    for (int i=0; i<4; i++){
      bytes[i] = global_buffer[i];   //NOTE CHange the order?
    }

    //std::bitset<32> bits(bytes);
    std::bitset<8> bitset1(bytes[0]);
		std::bitset<8> bitset2(bytes[1]);
		std::bitset<8> bitset3(bytes[2]);
		std::bitset<8> bitset4(bytes[3]);

    std::string s1 = bitset1.to_string();
    std::string s2 = bitset2.to_string();
    std::string s3 = bitset3.to_string();
    std::string s4 = bitset4.to_string();
    std::bitset<32> bits( s1 + s2 + s3 + s4 );

    //unsigned int i = *global_buffer;

    uint8_t status = ((uint8_t) (global_buffer[0] & 0xC0) >> 6);
    uint16_t hum = ((uint16_t) (global_buffer[0] & 0x3f) << 8)  | ((uint16_t) global_buffer[1] );
    uint16_t temp = ((uint16_t) (global_buffer[2]) << 8)  | ((uint16_t) (global_buffer[3] & 0xFC) );


    //std::cout << "unsigned int : " << i << std::endl;


    this->bitsetI2C = bits;
    std::cout << "print bitset: " << bits << std::endl;
    std::bitset<8> stat(status);
    std::bitset<16> humidit(hum);
    std::bitset<16> tem(temp);

    std::cout << "print status : " << stat << std::endl;
    std::cout << "print hum : " << humidit << std::endl;
    std::cout << "print temp : " << tem << std::endl;

    std::cout << "print status : " << (unsigned int)status << std::endl;
    std::cout << "print hum : " << (unsigned int)hum << std::endl;
    std::cout << "print temp : " << (unsigned int)temp << std::endl;
  }
  std::cout << "size of buffer: " << nbOfBytes << std::endl;
  //std::cout << "print buffer: " << *global_buffer << std::endl;

}

int TemperatureAndHumidity::getStatus(){
  std::bitset<2> status;
  status[0] = this->bitsetI2C[0]; //NOTE endre til MOST significant bit??
  status[1] = this->bitsetI2C[1];
  return status.to_ulong();

}

double TemperatureAndHumidity::getTemp(){

  std::bitset<14> tempBits;

  std::string s = this->bitsetI2C.to_string();


  for (int i=0; i <14; i++){
    tempBits[i] = this->bitsetI2C[i+16]; //NOTE eller motsatt?
  }
  std::cout << "print tempbitset: " << tempBits << std::endl;
  double temp = (( tempBits.to_ulong() / (2^14 - 2)) * 165 ) - 40;
  return temp;
}

double TemperatureAndHumidity::getHum(){

  std::bitset<14> humBits;

  for (int i=0; i <14; i++){
    humBits[i] = this->bitsetI2C[i+16]; //NOTE eller motsatt?
  }

  double hum = ((humBits.to_ulong() / (2^14 - 2)) * 100 );
  return hum;
}



TemperatureAndHumidity::~TemperatureAndHumidity(){
  delete bus;
}
