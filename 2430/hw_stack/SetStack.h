#pragma once
#ifndef SETSTACK_H
#define SETSTACK_H
#include <iostream>
#include <string>
#include<vector>
#endif
#include"Stack.h"

std::string postfix(std::string exp1); // returns postfix expression

class SetStack{ // Stack for evaluating the operations with sets
private:
	Stack *topNode; // stack as a set of elements
	SetStack *next; // pointer to the next stack-set
public:
	SetStack(); //default constructor
	~SetStack(); //destructor
	bool isEmpty(); 
	void pop(); 
	void push(Stack *s);
	Stack* top();
};

Stack* postfixExpEval(std::string exp); //evaluates the postfix expression

extern std::vector<SetStack*> SetStackGlobal;