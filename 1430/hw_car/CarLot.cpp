#include "CarLot.h"

int CarLot::numOfCars = 0;

CarLot::CarLot(): model(""), repairSize(0), repairs(NULL){}

CarLot::CarLot(const string &info): repairs(NULL) {
	//create a stringstream obj on input string base to read model name and all codes 
	//(while reading from stringstream is corrected)
	stringstream stream (info);
	stream >> model;
	//create temporal vector of type int object to hold all codes
	vector<int> temp;
	int temp_number;
	while (stream >> temp_number)
		temp.push_back(temp_number);
	//if no codes all only one code == 0 then size = 0
	if (temp.size() == 0 || (temp.size() == 1 && temp[0] == 0))
		repairSize = 0;
	
	else {
		repairSize = temp.size();
		repairs = new int[repairSize];
		for(size_t i = 0; i < temp.size(); i++)
			repairs[i] = temp[i];
		
	}
	numOfCars++;
}

CarLot::~CarLot(){
	if (repairs)
		delete[] repairs;
	numOfCars--;
}

void CarLot::printCar(const vector<RepairList> &list){
	cout << "Car Model: " << model << endl;
	//if size == 0 then throw an exception
	if (!repairSize) throw ("Pass: car is done\n");
	
	
	for(int i = 0; i < repairSize; i++){
		cout << "Repair #" << i+1 << ":";
		//find in vector of RepairList objects appropriate struct with the same code and display it path
		for(size_t j = 0; j < list.size(); j++)
			if (list[j].repairCode == repairs[i]){
				cout << list[j].repairPart << endl;
				break;
			}
	}
	cout << endl;
}