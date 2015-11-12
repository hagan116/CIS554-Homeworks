/*
	Sam Hagan
	CIS 554 Homework 6
	location.cpp

	This file contains the implementation of the Location class. There is a constructor
	which initializes the sets described in the location.h file, and a method called
	getLocation(Point & p). getLocation(Point & p) takes a point and returns the corresponding
	LOCATION.
*/
#include "location.h"
#include <vector>
using namespace std;

Location::Location() : nyX(), nyY(), sfX(), sfY(), laX(), laY(), chiX(), chiY() {
	int nyInts[] = {1,2,3,4,5};
	vector<int> nyVector (nyInts, nyInts + sizeof(nyInts) / sizeof(int));
	nyX.setValues(nyVector);
	nyY.setValues(nyVector);

	int sfInts[] = {6,7,8,9,10};
	vector<int> sfVector (sfInts, sfInts + sizeof(sfInts) / sizeof(int));
	sfX.setValues(sfVector);
	sfY.setValues(sfVector);

	int laInts[] = {11,12,13,14,15};
	vector<int> laVector (laInts, laInts + sizeof(laInts) / sizeof(int));
	laX.setValues(laVector);
	laY.setValues(laVector);

	int chiInts[] = {16,17,18,19,20};
	vector<int> chiVector (chiInts, chiInts + sizeof(chiInts) / sizeof(int));
	chiX.setValues(chiVector);
	chiY.setValues(chiVector);
}

Location::LOCATION Location::getLocation(Point & p){
	int x = p.getX();
	int y = p.getY();

	if (nyX.isMember(x) && nyY.isMember(y)){
		return NEWYORK;
	}
	else if (sfX.isMember(x) && sfY.isMember(y)){
		return SANFRANCISCO;
	}
	else if (laX.isMember(x) && laY.isMember(y)){
		return LOSANGELES;
	}
	else if (chiX.isMember(x) && chiY.isMember(y)){
		return CHICAGO;
	}
	else {
		return NOT_FOUND;
	}
}