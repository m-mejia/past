#include"Point.h"
//default constructor 
Point::Point(){
	this->x = 0;
	this->y = 0;
}

//constructor with parameters
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

//setters
void Point::setX(double x) {
	this->x = x;
}

void Point::setY(double y) {
	this->y = y;
}

//getters
double Point::getX() {
	return this->x;
}

double Point::getY() {
	return this->y;
}