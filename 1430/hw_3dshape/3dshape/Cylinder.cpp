#include"Cylinder.h"

//default constructor
Cylinder::Cylinder() {
	this->x = 0;
	this->y = 0;
	this->r = 0;
	this->h = 0;
}
//constructor with parameters
Cylinder::Cylinder(double x, double y, double r, double h) {
	this->x = x;
	this->y = y;
	this->r = r;
	this->h = h;
}

//getter
double Cylinder::getHeight() {
	return this->h;
}
//setter
void Cylinder::setHeight(double h) {
	this->h = h;
}
//calc area
double Cylinder::area() {
	double area = 2 * 3.14 * this->r * (this->r + this->h);
	return area;
}
//calc volume
double Cylinder::calcVolume() {
	double volume = 3.14 * this->r * this->r * this->h;
	return volume;
}