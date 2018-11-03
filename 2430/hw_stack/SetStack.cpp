#include "SetStack.h"
#include<fstream>

int priority(char a) 
{
	switch (a)
	{
	case '*': return 3;
	case '+': return 2;
	case ')': return 1;
	case '(': return 0;
	}
	return 0;
}

std::string postfix(std::string exp1)
{
	std::string exp2 = "";
	for (unsigned int i = 0; i < exp1.length(); i++) // erasing unsuitable symbols in this loop
	{
		if (exp1[i] == '+' || exp1[i] == '*')
		{
			int j = i - 1;
			if (i == 0)
			{
				exp1.erase(i, 1);
				i--;
			}
			else if (!((exp1[j] >= 'a' && exp1[j] <= 'z') || (exp1[j] >= 'A' && exp1[j] <= 'Z') || exp1[j] == ')'))
			{
				exp1.erase(i, 1);
				i--;
			}
		}
		else
		{
			if (!((exp1[i] >= 'a' && exp1[i] <= 'z') || (exp1[i] >= 'A' && exp1[i] <= 'Z') || exp1[i] == ')' || exp1[i] == '('))
			{
				exp1.erase(i, 1);
				i--;
			}
		}
	}
	Stack *stack = new Stack();
	for (unsigned int i = 0; i < exp1.length(); i++)
	{
		if ((exp1[i] >= 'a' && exp1[i] <= 'z') || (exp1[i] >= 'A' && exp1[i] <= 'Z'))
		{
			exp2 += exp1[i];
		}
		else if (exp1[i] == ' ')
		{
			while (exp1[i] == ' ') i++;
			i--;
		}
		if (exp1[i] == '(')
		{
			std::string temp = "";
			stack->push(temp + exp1[i]);
		}
		else if (exp1[i] == ')')
		{
			while (!stack->isEmpty() && stack->top() != "(")
			{
				exp2 += stack->top();
				stack->pop();
			}
			if (stack == nullptr)
			{
				std::cout << "Input error. Please, check the data.\n\n";
				return "";
			}
			else stack->pop();
		}
		else if (exp1[i] == '+' || exp1[i] == '*')
		{
			while (!stack->isEmpty() && priority(exp1[i]) <= priority(stack->top()[0]))
			{
				exp2 += stack->top();
				stack->pop();
			}
			std::string temp = "";
			stack->push(temp + exp1[i]);
		}
	}
	while (!stack->isEmpty())
	{
		if (stack->top() == "(") // the odd '('-symbol
		{
			std::cout << "Input error. Please, check the data.\n\n";
			return "";
		}
		exp2 += stack->top();
		stack->pop();
	}
	delete stack;
	return exp2;
}

SetStack::SetStack()
{
	this->topNode = NULL;
	this->next = NULL;
}

SetStack::~SetStack()
{
	if (this->next != NULL)
	{
		int k = -1;
		for (int i = 0; i < StackGlobal.size(); i++)
		{
			if (StackGlobal[i] == this->next->topNode)
			{
				k = i;
				break;
			}
		}
		if (k < 0){
			delete this->next->topNode;
			this->topNode = NULL;
		}
		delete this->next;
		this->next = NULL;
	}
	if (this->topNode != NULL)
	{
		int k = -1;
		for (int i = 0; i < StackGlobal.size(); i++)
		{
			if (StackGlobal[i] == this->topNode)
			{
				k = i;
				break;
			}
		}
		if (k < 0){
			delete this->topNode;
			this->topNode = NULL;
		}
	}
}

bool SetStack::isEmpty()
{
	return (this->topNode == NULL);
}

void SetStack::pop()
{
	this->topNode = this->next->topNode;
	this->next = this->next->next;
}

void SetStack::push(Stack *S)
{
	SetStack *ss = new SetStack();
	ss->topNode = this->topNode;
	ss->next = this->next;
	this->next = ss;
	this->topNode = S;
	SetStack *cur = ss;
	if (!SetStackGlobal.empty())
		SetStackGlobal.pop_back();
	SetStackGlobal.push_back(ss);
}

Stack* SetStack::top()
{
	return this->topNode;
}

Stack* postfixExpEval(std::string exp)
{
	SetStack *sets = new SetStack();
	for (unsigned int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '+') // if we have '+' then get operands op1 & op2 from the stack. After that push to the stack
		{					// the result of op1 + op2
			Stack *op1, *op2;
			if (sets->isEmpty())
			{
				std::cout << "Something is wrong. Please check the expression.\n\n";
				return NULL;
			}
			else
			{
				op1 = (sets->top());
				sets->pop();
				if (sets->isEmpty())
				{
					std::cout << "Something is wrong. Please check the expression.\n\n";
					return NULL;
				}
				else
				{
					op2 = (sets->top());
					sets->pop();
					Stack *res = new Stack(*op1 + *op2);
					sets->push(res);
				}
			}
		}
		else if (exp[i] == '*') //actions like in '+'-case
		{
			Stack *op1, *op2;
			if (sets->isEmpty())
			{
				std::cout << "Something is wrong. Please check the expression.\n\n";
				return NULL;
			}
			else
			{
				op1 = (sets->top());
				sets->pop();
				if (sets->isEmpty())
				{
					std::cout << "Something is wrong. Please check the expression.\n\n";
					return NULL;
				}
				else
				{
					op2 = (sets->top());
					sets->pop();
					Stack *res = new Stack(*op1 * *op2);
					sets->push(res);
				}
			}
		}
		else if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')) // read elements from the file to stack
		{																			// then push that stack to the 'SetStack'
			std::string filename = ""; 
			filename += toupper(exp[i]);
			filename += ".txt";
			std::ifstream f(filename);
			if(f.good())
			{
				Stack *stack = new Stack();
				do
				{
					std::string num;
					f >> num;
					if (num != "")
						stack->push(num);
				}while (!f.eof());
				sets->push(stack);
				StackGlobal.push_back(stack);
			}
			else
			{
				std::cout << "There is no file with a set.\nThe expression cannot be evaluated!\n\n";
				return NULL;
			}
		}
	}
	Stack *ans = sets->top(); // in the end, we have the final result in our 'SetStack'
	sets->pop();
	delete sets;
	return ans;
}