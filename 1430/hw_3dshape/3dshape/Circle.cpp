#include"Circle.h"
//default constructor
Circle::Circle() {
	this->x = 0;
	this->y = 0;
	this->r = 0;
}
//constructor with parameters
Circle::Circle(double x, double y, double r) {
	this->x = x;
	this->y = y;
	this->r = r;
}
//getter
double Circle::getRadius() {
	return this->r;
}
//setter
void Circle::setRadius(double r) {
	this->r = r;
}
//calc area
double Circle::area() {
	double area = this->r * this->r * 3.14;
	return area;
}