
main: main.o I2C.o TemperatureAndHumidity.o
	g++ -o main main.o I2C.o TemperatureAndHumidity.o

I2C.o: I2C.hpp I2C.cpp
	g++ -o I2C.o -c I2C.cpp

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
