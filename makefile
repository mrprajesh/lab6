CXX = g++
CFLAGS = -Wall -g
lab6 : main.o Point.o
	$(CXX) $(CFLAGS) -o lab6 main.o
main.o : main.cpp 
	$(CXX) $(CFLAGS) -c main.cpp
Point.o: Point.h

