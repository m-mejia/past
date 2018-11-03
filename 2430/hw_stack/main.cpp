#include <vld.h>
#include <iostream>
#include<string>
#include"SetStack.h"
#include<fstream>

std::vector<SetStack*> SetStackGlobal;
std::vector<Stack*> StackGlobal;
std::vector<Node*> NodeGlobal;

int main(/*int argc, char *argv[]*/) {
	std::cout << "Please enter the name of file with expression. (Example: 1.txt)\n";
	std::string src;
	std::cin >> src;
	std::cout << "Please enter the name of file for saving the result. (Example: ans1.txt)\n";
	std::string dst;
	std::cin >> dst;
	std::ifstream fin(src);
	if (fin.good()){
		std::ofstream fout(dst);
		while (!fin.eof())
		{
			std::string exp = "";
			std::getline(fin, exp);
			std::cout << "The infix expression: " << exp << std::endl;
			std::string postfixexp = postfix(exp);
			std::cout << "The postfix expression: " << postfixexp << std::endl;
			if (postfixexp != ""){
				Stack *result = postfixExpEval(postfixexp);
				if (result != NULL){
					result->sort();
					std::cout << "The result of evaluation: ";
					result->print();
					fout << exp << "=";
					result->FilePrint(fout);
				}
				for (unsigned int i = 0; i < SetStackGlobal.size(); i++)
					if (SetStackGlobal[i] != NULL)
						delete SetStackGlobal[i];
				for (unsigned int i = 0; i < StackGlobal.size(); i++)
					if (StackGlobal[i] != NULL)
					{
						delete StackGlobal[i];
					}
				for (unsigned int i = 0; i < NodeGlobal.size(); i++)
					if (NodeGlobal[i] != NULL)
						delete NodeGlobal[i];
				StackGlobal.clear();
				SetStackGlobal.clear();
				NodeGlobal.clear();
			}
		}
	}
	else
	{
		std::cout << "File with expression does not exist.\n\n";
	}
	std::cout << "The session is over. Thank you. (Press ENTER to quit)\n";
	std::cin.sync();
	std::cin.get();
	return 0;
}
