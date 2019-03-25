#include "Fan.hpp"


Fan::Fan(int gpio, int interruptPin){
  saved_Input_pointer[0] = this;
  this->gpio = gpio;
  this->interruptPin = interruptPin;
  wiringPiSetupGpio();
  pinMode(this->gpio, PWM_OUTPUT);
  pinMode(this->interruptPin, INPUT);
  int state = wiringPiISR(this->interruptPin, INT_EDGE_BOTH, helper_function[0]);
  //wiringPiISR(this->interruptPin, INT_EDGE_RISING, &start);
  //wiringPiISR(this->interruptPin, INT_EDGE_FALLING, &stop);
}


//range is 0-1024
void Fan::setPwm(int pwm_value){
  pwmWrite(this->gpio, pwm_value);
}

void Fan::start(){
  pwmWrite(this->gpio, 1023);
}

void Fan::stop(){
  pwmWrite(this->gpio, 0);
}

static void helper_func0()
{
	std::cout << "in helper_func for pin 0: "<<std::endl;
  saved_Fan_pointer[0]->onInterrupt();
}
static void helper_func1()
{
  cout << "in helper_func for pin 1: ";
  saved_Input_pointer[1]->interruptEdge();
}
static void(*helper_function[2])() = {
  helper_func0,
  helper_func1
};
void Fan::onInterrupt(){
  if (digitalRead(this->interruptPin) == HIGH){
    start();
  }
  else{
    stop();
  }
}


Fan::~Fan(){
  //stop fan
  this->stop();
}
