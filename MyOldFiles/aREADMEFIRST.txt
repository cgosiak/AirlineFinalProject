I did not comment my entire program as it was unnecessary for the current program, however, I will be sure to add sufficient commenting for future projects.
- Caleb


A brief writeup of program 3:
	I decided, given the length of the program development time, that I was going to work on creating a more OOD with the flight program. I thought the best place to start would be to modularize my code; by making classes. The classes I used with short descriptions:
	Plane:
		The Plane class is the intermediary between the visual user program and the backend that is connecting all my classes.
		This is where the proceeding classes are generated into pbject after sufficient data has been obtained. Such as; rows, 
		columns, and other various plane elements.

	SeatMap:
		This is the class in which my 2d pointed array is generated that houses a mappping of seats. This class is important
		for handling anything that deals with my pointed 2d array. And also serves as an intermediary to bypass certain 
		program elements that are not used for program 3, but are intended to be used later.
	Seat:
		Probably my favorite class. This handles useful information about each indinidual seat:
			-price
			-seating type
			-is it reserved
			-various other variables
		This is the final step in the program as previous classes speak "down the stream" to access the methods and data
		from this class.
	UsefulFunctions:
		This is a class that I either intend to make more robust, or to convert it to a namespace for later use.
		Currently it contains "Useful Functions" that I use over and over throughout my program and its corresponding classes.

The Testing Process: