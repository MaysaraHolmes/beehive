#include "Fan.hpp"


//NOTE take the pin as parameter
Fan::Fan(int gpio){
  this->gpio = gpio;
  //wiringPiSetupGpio();
  //pinMode(this->gpio, PWM_OUTPUT);
}

//range is 0-1024
void Fan::setPwm(int pwm_value){
  //pwmWrite(this->gpio, pwm);
}

void Fan::stop(){
  //pwmWrite(this->gpio, pwm);
}


Fan::~Fan(){
  //stop fan
  this->stop();
}
