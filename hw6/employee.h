/*
	Sam Hagan
	CIS 554 Homework 6
	employee.h

	This is a header file for the Employee class, which consists of a name for
	the employee in the form of a string, and a location in the form of a Point.
*/
#include "point.h"
#include <string>
using namespace std;

class Employee{
public:
    Employee(string &, Point &);
    
    void setCoordinates(Point &); //Setters
    void setName(string &);
    
    Point getCoordinates(); //Getters
    string getName();
private:
    Point coordinates;
    string name;
};
