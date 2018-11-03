#include"Point.h"

//use virtual function because I need realisation this function in base class

class Circle:public Point {
protected:
	double r;
public:
	Circle();
	Circle(double, double, double);
	double getRadius();
	void setRadius(double);
	virtual double area();
};