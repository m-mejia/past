#ifndef CARLOT_H
#define CARLOT_H

#include "RepairList.h"

#include <vector>
#include <sstream>
#include <iostream>

#define FIXED_SIZE 5

class CarLot{
private:
	string model;
	int repairSize, *repairs;
	static int numOfCars;
public:
	CarLot();
	CarLot(const string &info);
	~CarLot();
	void printCar(const vector<RepairList> &list);
	
};
#endif