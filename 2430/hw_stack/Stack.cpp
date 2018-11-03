#include"Stack.h"
#include<fstream>
Stack::Stack()
{
	topNode = NULL;
}

Stack::~Stack()
{
	Node *cur = this->topNode;
	if (this != NULL){
		if (cur != NULL){
			if (cur->next != NULL)
			{
				int j = -1;
				for (unsigned i = 0; i < NodeGlobal.size(); i++)
				{
					if (NodeGlobal[i] == cur->next)
					{
						j = i;
						break;
					}
				}
				if (j >= 0)
					NodeGlobal.erase(NodeGlobal.begin() + j);
				delete cur->next;
				this->topNode->next = NULL;
			}
			int k = -1;
			for (unsigned i = 0; i < NodeGlobal.size(); i++)
			{
				if (NodeGlobal[i] == cur)
				{
					k = i;
					break;
				}
			}
			if (k >= 0)
				NodeGlobal.erase(NodeGlobal.begin() + k);
			delete cur;
			cur = NULL;
			this->topNode = NULL;
		}
	}
}

bool Stack::isEmpty()
{
	return (this->topNode == NULL);
}

void Stack::pop()
{
	Node *cur = this->topNode;
	this->topNode = this->topNode->next;
	cur->next = NULL;
	int k = -1;
	for (unsigned i = 0; i < NodeGlobal.size(); i++)
	{
		if (NodeGlobal[i] == cur)
		{
			k = i;
			break;
		}
	}
	if (k >= 0)
		NodeGlobal.erase(NodeGlobal.begin() + k);
	delete cur;
	cur = NULL;
}

void Stack::push(const std::string s)
{
	Node *cur = new Node();
	cur->data = s;
	cur->next = this->topNode;
	this->topNode = cur;
	NodeGlobal.push_back(cur);
}

void Stack::print() const
{
	Node *cur = this->topNode;
	if (cur != NULL)
	{
		while (cur != NULL)
		{
			std::cout << cur->data << " ";
			cur = cur->next;
		}
		std::cout << "\n\n";
	}
	else
		std::cout << "The stack is empty.\n\n";
}

void Stack::sort()
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		Node *cur = this->topNode;
		if (cur != NULL){
			while (cur->next != NULL)
			{
				if (std::stoi(cur->data) > std::stoi(cur->next->data))
				{
					std::string temp = cur->data;
					cur->data = cur->next->data;
					cur->next->data = temp;
					flag = true;
				}
				cur = cur->next;
			}
		}
	}
}

Stack::Stack(const Stack& stack)
{
	this->topNode = stack.topNode;
}

void Stack::FilePrint(std::ofstream &out) const
{
	Node *cur = this->topNode;
	if (cur != NULL)
	{
		while (cur != NULL)
		{
			out << cur->data << " ";
			cur = cur->next;
		}
		out << "\n";
	}
	else
		out << "The stack is empty.\n\n";
}

Stack Stack::operator + (const Stack& other) const{
	Node *otherNode = other.topNode;
	Node *cur = this->topNode;
	Stack *stack = new Stack();
	while (cur != NULL)
	{
		stack->push(cur->data);
		cur = cur->next;
	}
	while (otherNode != NULL)
	{
		cur = this->topNode;
		bool flag = true;
		while (cur != NULL)
		{
			if (cur->data == otherNode->data)
			{
				flag = false;
				break;
			}
			cur = cur->next;
		}
		if (flag)
		{
			stack->push(otherNode->data);
		}
		otherNode = otherNode->next;
	}
	StackGlobal.push_back(stack);
	return *stack;
}

Stack Stack::operator * (const Stack& other) const
{
	Stack *stack = new Stack();
	Node *otherNode = other.topNode;
	Node *cur = this->topNode;
	while (cur != NULL)
	{
		otherNode = other.topNode;
		while (otherNode != NULL)
		{
			if (cur->data == otherNode->data)
			{
				stack->push(cur->data);
				break;
			}
			otherNode = otherNode->next;
		}
		cur = cur->next;
	}
	StackGlobal.push_back(stack);
	return *stack;
}

Stack& Stack::operator=(const Stack& other)
{
	this->topNode = other.topNode;
	return *this;
}
