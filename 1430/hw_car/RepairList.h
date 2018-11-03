#ifndef REPAIR_LIST_H
#define REPAIR_LIST_H

#include <string>
using namespace std;

struct RepairList{
	int repairCode;
	string repairPart;
	//default & parameter constructor for struct obj
	RepairList(int code = -1, string part = ""):
		repairCode(code), repairPart(part){}
};

#endif