#include "CarLot.h"

#include <fstream>

int main () {
	//open two files and check on opened
	ifstream repairsFile("RepairsKey.txt");
	if (!repairsFile.is_open()){
		cout << "Cannot open RepairsKey.txt" << endl;
		return -1;
	}
	
	ifstream carFile("Cars.txt");
	if (!carFile.is_open()){
		cout << "Cannot open Cars.txt" << endl;
		repairsFile.close();
		return -1;
	}
	
	vector<RepairList> repairs;
	while (!repairsFile.eof()){
		int code;
		string path;
		repairsFile >> code;
		getline(repairsFile, path);
		repairs.push_back(RepairList(code, path));
	}
	repairsFile.close();
	
	vector<CarLot *> cars;
	
	while (!carFile.eof()){
		string temp;
		getline(carFile, temp);
		if (temp == "" || temp == "\n") continue;
		cars.push_back(new CarLot(temp));
	}
	carFile.close();
	
	for(size_t i = 0; i < cars.size(); i++){
		
		//try to find (catch) exception
		try{
			cars[i]->printCar(repairs);
		}
		//work with exception
		catch(const char * err){
			cout << err << endl;
		}
	}
	
	//free memory
	for(size_t i = 0; i < cars.size(); i++)
		delete cars[i];
	
	return 0;
}