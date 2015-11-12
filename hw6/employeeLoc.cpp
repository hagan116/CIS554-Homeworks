/*
	Sam Hagan
	CIS554 Homework 6
	employeeLoc.cpp

	This file contains a main() method, which loops infinitely. Inside the loop, the method
	prompts the user for a name, and x and y coordinates. The method then prints where the
	entered person is.
*/
#include "location.h"
#include "employee.h"
#include <iostream>
#include <string>

int main() {
	Location l;
	Location::LOCATION inputLocation;
	string name;
	int xPosition;
	int yPosition;

	for (;;){
		cout << "Enter employee name: ";
		cin >> name;

		cout << "Enter X position (-1 to quit): ";
		cin >> xPosition;
		if (xPosition == -1){
			break;
		}

		cout << "Enter Y position (-1 to quit): ";
		cin >> yPosition;
		if (yPosition == -1){
			break;
		}

		Point inputPoint(xPosition,yPosition); // Create a point with the user's input
		Employee inputEmployee(name,inputPoint); // Create an employee with the user's input and point

		inputLocation = l.getLocation(inputPoint);

		switch (inputLocation){
			case (Location::NEWYORK):
				cout << name << " is in New York City." << endl;
				break;
			case (Location::SANFRANCISCO):
				cout << name << " is in San Francisco." << endl;
				break;
			case (Location::LOSANGELES):
				cout << name << " is in Los Angeles." << endl;
				break;
			case (Location::CHICAGO):
				cout << name << " is in Chicago." << endl;
				break;
			case (Location::NOT_FOUND):
				cout << name << " can't be found." << endl;
				break;
		}
	}

	return 0;
}