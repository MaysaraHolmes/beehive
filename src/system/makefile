
main: main.o I2C.o TemperatureAndHumidity.o ReadI2CDevices.o#ADC.o
	g++ -pthread -lwiringPi -lwiringPiDev -o main main.o I2C.o TemperatureAndHumidity.o ReadI2CDevices.o #ADC.o

Pressure.o: Pressure.hpp Pressure.cpp
	g++ -o Pressure.o -c Pressure.cpp

#ADC.o: ADC.hpp ADC.cpp
#	g++ -o ADC.o -c ADC.cpp
Sensor.o: Sensor.hpp
	g++ -o Sensor.o -c

I2C.o: I2C.hpp I2C.cpp
	g++ -o I2C.o -c I2C.cpp

ReadI2CDevices.o: ReadI2CDevices.hpp ReadI2CDevices.cpp
	g++ -o ReadI2CDevices.o -c ReadI2CDevices.cpp

TemperatureAndHumidity.o: TemperatureAndHumidity.hpp TemperatureAndHumidity.cpp
	g++ -o TemperatureAndHumidity.o -c TemperatureAndHumidity.cpp

main.o: main.cpp
	g++ -o main.o -c main.cpp

clean:
	rm -f *.o main

#-------------------------------------------------------------

run: main
	./main


#
# build: clean out.out
#
# %.o: %.cpp
# 	g++ -c $<

#====================================================
