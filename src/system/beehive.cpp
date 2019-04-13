//! Project start
/*!
   Create a Fan object so the interrupt bin is set to the default value
   (using the default gpio pin in the Fan constructor)
   Create a TimerEvent object to start the timer which trigger the sensor-readings.
*/

#include "TimerEvent.hpp"
#include "Fan.hpp"


int main(int argc, const char* argv[] ){
  Fan* f = new Fan();
  f->stop();

  TimerEvent TimerEvent;
	TimerEvent.start(2000000000);

  do {
		sleep(1);
	} while (1);

  return 0;
}
