#pragma once
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include<vector>
#endif

struct Node {
    std::string data;
    Node *next;
};


class Stack {
public:
    Stack(); //default constructor
    ~Stack(); //deconstruct
	Stack(const Stack& stack); //copy constructor
    
    bool isEmpty(); //check if the top is null
	std::string top() const{
		return this->topNode->data;
	}; //get top element of stack should return top->top
    void pop();
    //remove top element of stack
    //create node *temp = this->top
    //reassign this->top = top->next
    //delete temp
    //post: top element has been removed
    //post: this->top now points to the next element down the stack
    //or NULL if the last element was removed
    void push (const std::string s);
    //create a new node with data=s;
    //newnode.ext should point to this->top
    //this->top should be reassigned to
	Stack operator + (const Stack& other) const; //should perform union (this, other)
	Stack operator * (const Stack& other) const; //intersection(this, other)
	Stack &operator =(const Stack& other);
    void print() const; //output the contents
    void sort();
	void FilePrint(std::ofstream &out) const; // prints into the file

private:
    Node *topNode;
};

extern std::vector<Stack*> StackGlobal;
extern std::vector<Node*> NodeGlobal;