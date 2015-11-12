/*
	Sam Hagan
	CIS 554 Homework 6
	point.cpp

	This file contains the implementation of the Point class. The point class has a 
	default constructor which initializes the only two instance variables to zero,
	and a second constructor which sets instance variables based on provided arguments.
	There are also setters/getters.
*/
#include "point.h"

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int xArg, int yArg){
    x = xArg;
    y = yArg;
}

void Point::setX(int xArg){
    x = xArg;
}

void Point::setY(int yArg){
    y = yArg;
}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}