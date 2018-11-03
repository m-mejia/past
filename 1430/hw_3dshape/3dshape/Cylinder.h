#include"Circle.h"

//use Multilevel Inheritance:In this type of inheritance the derived class inherits from a class, 
//which in turn inherits from some other class.
//The Super class for one, is sub class for the other.

class Cylinder :public Circle {
private:
	double h;
public:
	Cylinder();
	Cylinder(double, double, double, double);
	double getHeight();
	void setHeight(double);
	double area();
	double calcVolume();
};