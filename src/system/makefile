
main: main.o I2C.o
	g++ -o main main.o I2C.o

I2C.o: I2C.hpp I2C.cpp
	g++ -o I2C.o -c I2C.cpp

main.o: main.cpp
	g++ -o main.o -c main.cpp

clean:
	rm -f *.o main

#-------------------------------------------------------------

# run: out.out
# 	./out.out
#
# clean:
# 	rm -f *.o
# 	rm -f *.out
#
# build: clean out.out
#
# %.o: %.cpp
# 	g++ -c $<

#====================================================
