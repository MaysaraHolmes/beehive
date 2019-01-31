#ifndef I2C_HPP
#define I2C_HPP

#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port

#include <stdio.h>
#include <iostream>
#include <bitset>


class I2C{

	public:

		int file_i2c;

		//data buffer
		unsigned char buffer[60] = {0}; //NOTE in lec: char buf[2];

		//Constructor to open the I2C bus
		//and tell the kernel the I2C address of the slave
    I2C(char* portI2C, int addrI2C);

    void readI2C(int bytesToRead);
    int writeI2C(int length); //NOTE instead overload function?

};

#endif // I2C_HPP
