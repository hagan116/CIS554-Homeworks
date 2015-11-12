/*
	Sam Hagan
	CIS 554 Homework 6
	employee.cpp

	This file contains the implementation of the Employee class. The class consists
	solely of a constructor which takes a string and a Point, and setters/getters.
*/
#include "employee.h"

Employee::Employee(string & nameArg, Point & coordArg){
    coordinates = coordArg;
    name = nameArg;
}

void Employee::setCoordinates(Point & coordArg){
    coordinates = coordArg;
}

void Employee::setName(string & nameArg){
    name = nameArg;
}

Point Employee::getCoordinates(){
    return coordinates;
}

string Employee::getName(){
    return name;
}