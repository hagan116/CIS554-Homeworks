/*
	Sam Hagan
	CIS 554 Homework 6
	location.h

	This is a header file for the Location class. The Location class has an enumeration
	called LOCATION, which enumerates the following locations: New York, San Fran., L.A.,
	and Chicago. There are two Sets per city, which contain truth values representing whether
	or not a coordinate falls within the city.
*/
#include "set.h"
#include "point.h"

class Location {
public:
	Location();
    enum LOCATION {NOT_FOUND, NEWYORK, SANFRANCISCO, LOSANGELES, CHICAGO};
    LOCATION getLocation(Point & p);
private:
	Set nyX;
	Set nyY;
	Set sfX;
	Set sfY;
	Set laX;
	Set laY;
	Set chiX;
	Set chiY;
};
