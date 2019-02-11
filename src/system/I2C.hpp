#ifndef I2C_HPP
#define I2C_HPP

#include <unistd.h>				//Needed for I2C port
#include <fcntl.h>				//Needed for I2C port
#include <sys/ioctl.h>			//Needed for I2C port
#include <linux/i2c-dev.h>		//Needed for I2C port

#include <stdio.h>
#include <iostream>
#include <bitset> //remove?


class I2C{

	public:

		int file_i2c;

		//data buffer
		unsigned char buffer[60] = {0}; //NOTE change to 4?

		//Constructor, open the I2C bus and tell the kernel the address of the slave
		I2C(char* portI2C, int slaveAddr[], int length);

    void readI2C(int bytesToRead, unsigned char* global_buffer);
    int writeI2C(int length); //NOTE instead overload function?

};

#endif // I2C_HPP
