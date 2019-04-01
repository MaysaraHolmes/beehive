#include "I2C.hpp"


I2C::I2C(char* portI2C, int slaveAddr){

	//----- OPEN THE I2C BUS -----
	char *filename = (char*)portI2C;
	if ((file_i2c = open(filename, O_RDWR)) < 0)
	{
		//ERROR HANDLING: you can check error to see what went wrong
		printf("Failed to open the I2C bus\n");
		return;
	}

	//tell the kernel the I2C address of the slave
	if (ioctl(file_i2c, I2C_SLAVE, slaveAddr) < 0){
		printf("Failed to acquire bus access and/or talk to slave.\n");
		//ERROR HANDLING;
		return;
	}
}


void I2C::readI2C(int bytesToRead, unsigned char* buffer){
	//----- READ BYTES -----
	//length = bytesToRead;			//<<< Number of bytes to read
	if (read(file_i2c, buffer, bytesToRead) != bytesToRead)		//read() returns the number of bytes actually read, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		printf("Failed to read from the i2c bus.\n");
	}
}



int I2C::writeI2C(int length, unsigned char* buffer){

	if (write(file_i2c, buffer, length) != length)		//write() returns the number of bytes actually written, if it doesn't match then an error occurred (e.g. no response from the device)
	{
		/* ERROR HANDLING: i2c transaction failed */
		printf("Failed to write to the i2c bus.\n");
		return -1;
	}
	return 1;
}
