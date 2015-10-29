CXX = g++
CC = g++
FLAGS = -std=c++11

all:		flightReservation

Plane.o: Plane.cpp Plane.h
	$(CXX) $(FLAGS) -c Plane.cpp 

SeatMap.o: SeatMap.cpp SeatMap.h
	$(CXX) $(FLAGS) -c SeatMap.cpp 

Seat.o: Seat.cpp Seat.h
	$(CXX) $(FLAGS) -c Seat.cpp 

UsefulFunctions.o: UsefulFunctions.cpp UsefulFunctions.h
	$(CXX) $(FLAGS) -c UsefulFunctions.cpp 

main.o: main.cpp Plane.h
	$(CXX) $(FLAGS) -c main.cpp 

flightReservation: Plane.o SeatMap.o Seat.o UsefulFunctions.o main.o
	$(CXX) $(FLAGS) Plane.o SeatMap.o Seat.o UsefulFunctions.o main.o -o flightReservation

clobber:
	rm -f *.o *.exe core flightReservation
