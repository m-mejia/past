#include <string>
#include <iostream>

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

struct Node {
    long long num;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
public:
    DoubleLinkedList();   // default construct
    ~DoubleLinkedList();  // deconstruct
    DoubleLinkedList(const std::string& num, int digitsPerNode); // user defined construct
    DoubleLinkedList(int digitsPerNode);
    DoubleLinkedList(const DoubleLinkedList& list);  // copy construct
    DoubleLinkedList& operator = (const DoubleLinkedList& list);  // assignment consturct
public:
    //mandatory
    DoubleLinkedList operator + (const DoubleLinkedList& list) const;
    DoubleLinkedList operator * (const DoubleLinkedList& list) const;
    
    // optional
    DoubleLinkedList operator - (const DoubleLinkedList& list) const;
    // 10% extra
    DoubleLinkedList operator / (const DoubleLinkedList& list) const;
	
public:
    const Node* GetHead() const;
    const Node* GetTail() const;
    void Append(Node* node);
    void Print() const;
private:
    Node* head;
    Node* tail;
    int m_digitsPerNode;
    long long remainder; // for / operator
    float decimal;  // for sqrt()  7 valid digits.
	
	// utility functions
	void Clear(); // clear all list elements
	void InsertFront(Node* node);  // insert new node to the front of the list
	long long ToLongLong() const; // returns number as long long
	void Normalize(); // delete leading zero nodes from the list
};

#endif
