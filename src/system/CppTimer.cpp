#include <stdio.h>
#include "CppTimer.h"
#include <unistd.h>



void DemoTimer1::timerEvent() {
	fprintf(stdout,"Buh! ");
	fflush(stdout);
}
