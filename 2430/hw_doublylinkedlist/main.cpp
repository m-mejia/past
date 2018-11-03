#include "ArgumentManager.h"
#include "DoubleLinkedList.h"

#include <iostream>
#include <fstream>
#include <cctype> // isalnum, isdigit, isalpha

// parse source line and get two numbers and operation
void parseLine(std::string line, std::string &num1, std::string &num2, std::string &op); 

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: infinitearithmetic \"input=xyz.txt;digitsPerNode=<number>\"\n";
    }
    ArgumentManager am(argc, argv);
    std::string filename = am.get("input");
    int digitsPerNode = std::stoi(am.get("digitsPerNode"));
    std::ifstream ifs(filename.c_str());
    std::string line;
    while (getline(ifs, line)){
        std::string num1;
        std::string num2;
        std::string op;
        // get num1 num2 and operator in line
        parseLine(line, num1, num2, op);
		
        DoubleLinkedList l1(num1, digitsPerNode);  // DoubleLinkedList(const std::string& num, int digitsPerNode)
        
        DoubleLinkedList l2(num2, digitsPerNode);
        DoubleLinkedList l;  // DoubleLinkedList();
        if (op == "+") // /* plus */
        {l = l1 + l2;}         // DoubleLinkedList operator + (const DoubleLinkedList& list) const;  DoubleLinkedList& operator = (const DoubleLinkedList& list);
        else if (op == "*")     // DoubleLinkedList operator * (const DoubleLinkedList& list) const;
        {l = l1 * l2;}
        else if ( op == "/")
        {l = l1 / l2;}         // DoubleLinkedList operator / (const DoubleLinkedList& list) const;
        else if (op == "-")
        {l = l1 - l2;}
		else {
			std::cout<< "Unknown operation: " << op << std::endl;
			continue;
		}
            
        // output result
		l1.Print();
		std::cout<< op;
		l2.Print();
		std::cout << "=";
		l.Print(); 
		std::cout << std::endl;
	}
        
    return 0;
}

void parseLine(std::string line, std::string &num1, std::string &num2, std::string &op)
{
	size_t i = 0;
	
	// read first number
	num1 = "";
	while (i < line.length() && isdigit(line[i])) {
		num1.append(1, line[i]);
		i++;
	}
	
	// skip all spaces
	while (i < line.length() && line[i] == ' ') i++;
		
	op = string(1, line[i]);
	
	// skip all spaces
	i++;
	while (i < line.length() && line[i] == ' ') i++;
	
	// read second number
	num2 = "";
	while (i < line.length() && isdigit(line[i])) {
		num2.append(1, line[i]);
		i++;
	}

}

