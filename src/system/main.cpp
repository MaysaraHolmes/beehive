
#include "ReadI2CDevices.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <stdio.h>
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include "CppTimer.h"
#include "Fan.hpp"

#include <unistd.h> //NOTE remove?


int main(int argc, const char* argv[] ){



  //TESTING FAN NOTE remove??
  Fan* f = new Fan();
  std::cout << "start fan" << std::endl;
  f->setPwm(1023);
  unsigned int microseconds = 5000000;
  usleep(microseconds);
  std::cout << "stop fan" << std::endl;
  f->stop();



  DemoTimer1 demoTimer1;
	demoTimer1.start(2000000000); //every 2sec

//NOTE remove??
wiringPiSetupGpio();
pinMode(22,INPUT);
int status = digitalRead(22);
printf("Pin input = %d\n", status);

  do {
		sleep(1);
	} while (1);


return 0;

}
