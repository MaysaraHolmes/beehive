#include "ReadI2CDevices.hpp"



ReadI2CDevices::ReadI2CDevices(){
  //this->bus1 = new I2C(I2C_PORT1, deviceAddrsPort1, NB_DEVICES_PORT1);
  //this->bus2 = new I2C(I2C_PORT2, deviceAddrsPort2, NB_DEVICES_PORT2);
  createSensorObjects();
}
void ReadI2CDevices::createSensorObjects(){
  //save to private list?
  //TemperatureAndHumidity th1(I2C_PORT1, ADDR_TEMP_AND_HUM);
  this->th1 = new TemperatureAndHumidity(I2C_PORT1, PORT1_ADDR_TEMP_AND_HUM);
  this->th2 = new TemperatureAndHumidity(I2C_PORT2, PORT2_ADDR_TEMP_AND_HUM);
  this->pr = new Pressure(I2C_PORT2, PORT2_ADDR_PRESSURE);

  //sensors[0] = new TemperatureAndHumidity(I2C_PORT2, PORT1_ADDR_TEMP_AND_HUM);

  //std::cout << "size of vector : " << sensors.size() << std::endl;
  //Sensor* s = new TemperatureAndHumidity(I2C_PORT2, PORT1_ADDR_TEMP_AND_HUM);
  //sensors.push_back(s);
  //sensors.push_back(new TemperatureAndHumidity(I2C_PORT2, PORT1_ADDR_TEMP_AND_HUM));
//std::cout << "size of vector : " << sensors.size() << std::endl;
}





void ReadI2CDevices::writeAll(){
  //for all sensors in this-> list
    //sensor.writeI2C;
  int i = (this->th1)->writeI2C();
  int j = (this->th2)->writeI2C();
  int k = (this->pr)->writeI2C();
  /*for (Sensor* s : this->sensors){
    s->writeI2C();
  }*/
}



void ReadI2CDevices::readAll(){//make attribute instead
  //(this->bus1)->readI2C(this->bytesToRead, global_buffer);
  //(this->bus1)->readI2C(this->bytesToRead, global_buffer);
  //maybe add one for each device?
  (this->th1)->readI2C(this->global_buffer);
  (this->th2)->readI2C(this->global_buffer);
  (this->pr)->readI2C(this->global_buffer);

  /*for (Sensor* s : this->sensors){
    s->readI2C(this->global_buffer);
  }*/
  std::cout << "\n\n TEMPERATUR I2C1 " << std::endl;
  std::cout << "status: " << ((TemperatureAndHumidity*)th1)->getStatus() << std::endl;
  std::cout << "temp: " << ((TemperatureAndHumidity*)th1)->getTemp() << std::endl;
  std::cout << "humidity: " << ((TemperatureAndHumidity*)th1)->getHum() << std::endl;
  //std::cout << "status: " << ((TemperatureAndHumidity*)sensors[0])->getStatus() << std::endl;
  //std::cout << "temp: " << ((TemperatureAndHumidity*)sensors[0])->getTemp() << std::endl;
  //std::cout << "humidity: " << ((TemperatureAndHumidity*)sensors[0])->getHum() << std::endl;

  std::cout << "\n\n TEMPERATUR I2C2 " << std::endl;
  std::cout << "status: " << ((TemperatureAndHumidity*)th2)->getStatus() << std::endl;
  std::cout << "temp: " << ((TemperatureAndHumidity*)th2)->getTemp() << std::endl;
  std::cout << "humidity: " << ((TemperatureAndHumidity*)th2)->getHum() << std::endl;

  std::cout << "\n\n PRESSURE " << std::endl;
  std::cout << "pressure: " << ((Pressure*)pr)->getPressure() << std::endl;
  std::cout << "temp: " << ((Pressure*)pr)->getTemp() << std::endl;


}


ReadI2CDevices::~ReadI2CDevices(){
  //delete this->bus1;
  //delete this->bus2;

  //delete s i sensors;
  delete th1;
  delete th2;
  delete pr;

  //for (Sensor* s : sensors){
    //delete s;
  //}
}
