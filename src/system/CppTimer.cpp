
#include "CppTimer.h"

DemoTimer1::DemoTimer1(){
	this->r = new ReadI2CDevices();
}


void DemoTimer1::timerEvent() {
  //call function ReadI2Cdevices
	fprintf(stdout,"Buh! ");
	fflush(stdout);

	
	r->writeAll();

	std::thread sensorThread(&ReadI2CDevices::readAll, r);
	sensorThread.join();


}

DemoTimer1::~DemoTimer1(){
	delete this->r;
	

}
