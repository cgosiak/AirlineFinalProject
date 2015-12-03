CXX = g++
CC = g++
FLAGS = -std=c++11

all:		flightReservation

Airport.o: Airport.cpp Airport.h
	$(CXX) $(FLAGS) -c Airport.cpp 

Flight.o: Flight.cpp Flight.h
	$(CXX) $(FLAGS) -c Flight.cpp 

Passenger.o: Passenger.cpp Passenger.h
	$(CXX) $(FLAGS) -c Passenger.cpp 

Plane.o: Plane.cpp Plane.h
	$(CXX) $(FLAGS) -c Plane.cpp 

SeatMap.o: SeatMap.cpp SeatMap.h
	$(CXX) $(FLAGS) -c SeatMap.cpp 

Seat.o: Seat.cpp Seat.h
	$(CXX) $(FLAGS) -c Seat.cpp 

UsefulFunctions.o: UsefulFunctions.cpp UsefulFunctions.h
	$(CXX) $(FLAGS) -c UsefulFunctions.cpp 

main.o: main.cpp
	$(CXX) $(FLAGS) -c main.cpp 

flightReservation: Airport.o Flight.o Passenger.o Plane.o SeatMap.o Seat.o UsefulFunctions.o main.o
	$(CXX) $(FLAGS) Airport.o Flight.o Passenger.o Plane.o SeatMap.o Seat.o UsefulFunctions.o main.o -o flightReservation

clobber:
	rm -f *.o *.exe core flightReservation
