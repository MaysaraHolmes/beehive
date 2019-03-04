
main: main.o I2C.o TemperatureAndHumidity.o ReadI2CDevices.o CppTimer.o
	g++ -pthread -o main main.o I2C.o TemperatureAndHumidity.o ReadI2CDevices.o CppTimer.o

#ADC.o: ADC.hpp ADC.cpp
#	g++ -o ADC.o -c ADC.cpp
Sensor.o: Sensor.hpp
	g++ -o Sensor.o -c

CppTimer.o: CppTimer.h CppTimer.cpp
	g++ -o CppTimer.o -c CppTimer.cpp

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
