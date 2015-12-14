#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T09:35:39
#
#-------------------------------------------------
QMAKE_CXXFLAGS += -std=c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FinalProjectGUI
TEMPLATE = app


SOURCES += main.cpp\
        planegui.cpp \
    seat.cpp \
    plane.cpp \
    flight.cpp \
    airport.cpp \
    seatmap.cpp \
    passenger.cpp \
    usefulfunctions.cpp

HEADERS  += planegui.h \
    seat.h \
    plane.h \
    flight.h \
    airport.h \
    seatmap.h \
    passenger.h \
    usefulfunctions.h

FORMS    += planegui.ui

DISTFILES += \
    ../../Desktop/FinalCS3528/SavedData/passengers.txt \
    ../../Desktop/FinalCS3528/SavedData/planes_and_flights.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_flight_1.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_flight_2.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_flight_3.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_flight_4.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_flight_5.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_plane_1.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_plane_2.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_plane_3.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_plane_4.txt \
    ../../Desktop/FinalCS3528/SavedData/saved_plane_5.txt
