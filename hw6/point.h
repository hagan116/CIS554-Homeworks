/*
	Sam Hagan
	CIS 554 Homework 6
	point.h

	This is a header file for the Point class.
*/
#ifndef POINT_H
#define POINT_H
class Point {
public:
    Point();
    Point(int, int);

    void setX(int); //Setters
    void setY(int);

    int getX(); //Getters
    int getY();
  
private:
    int x;
    int y;
};
#endif
