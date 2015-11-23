cmake_minimum_required(VERSION 3.3)
project(myProgram3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Plane.cpp Plane.h SeatMap.cpp SeatMap.h Seat.cpp Seat.h UsefulFunctions.cpp UsefulFunctions.h Flight.cpp Flight.h)
add_executable(Airline_Final ${SOURCE_FILES})