#include<iostream>
using namespace std;

class Point{
protected:
	double x;
	double y;
public:
	Point();
	Point(double, double);
	void setX(double);
	void setY(double);
	double getX();
	double getY();
};