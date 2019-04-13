#include "I2C.hpp"


I2C::I2C(char* portI2C, int slaveAddr){
	//open the I2c bus
	char *filename = (char*)portI2C;
	if ((file_i2c = open(filename, O_RDWR)) < 0){
		printf("Failed to open the I2C bus\n");
		return;
	}

	//tell the kernel the I2C address of the slave
	if (ioctl(file_i2c, I2C_SLAVE, slaveAddr) < 0){
		printf("Failed to acquire bus access and/or talk to slave.\n");
		return;
		}
}


void I2C::readI2C(int bytesToRead, unsigned char* global_buffer){
	if (read(file_i2c, global_buffer, bytesToRead) != bytesToRead){
		printf("Failed to read from the i2c bus.\n");
	}
}


int I2C::writeI2C(int length){
	buffer[0] = 0x01;
	buffer[1] = 0x02;
	if (write(file_i2c, buffer, length) != length){
		printf("Failed to write to the i2c bus.\n");
		return -1;
	}
	return 1;

}

int I2C::writeI2C(int length, unsigned char* buffer){
	if (write(file_i2c, buffer, length) != length){
		printf("Failed to write to the i2c bus.\n");
		return -1;
	}
	return 1;
}
