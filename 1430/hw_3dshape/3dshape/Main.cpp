#include"Cylinder.h"

int main() {
	Point p(12, 3);
	Cylinder cyl(12, 43, 2, 5);
	Circle cir(12, 34, 2);
	cout << "Point:(" << p.getX() << "," << p.getY() << ")" << endl;
	cout << "Area circle: " << cir.area() << endl;
	cout << "Area cylinder: " << cyl.area() << endl;
	cout << "Volume cylinder: " << cyl.calcVolume() << endl;
	return 0;
}
