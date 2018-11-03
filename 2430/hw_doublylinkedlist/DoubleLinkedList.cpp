
#include "DoubleLinkedList.h"
#include <cmath>
#include <iomanip>

DoubleLinkedList::DoubleLinkedList()   // default construct
{
	m_digitsPerNode = 2;
	head = nullptr;
	tail = nullptr;
	remainder = 0;
}
    

 // deconstruct
DoubleLinkedList::~DoubleLinkedList()
{
	// free all allocated memory 
	Clear();	
}


// user defined construct
DoubleLinkedList::DoubleLinkedList(const std::string& num, int digitsPerNode)
{
	Node *new_node;
	int digits;
	
	remainder = 0;
	if (digitsPerNode >=2 && digitsPerNode <= 8)
		m_digitsPerNode = digitsPerNode;
	else
		m_digitsPerNode = 2;
	
	head = nullptr;
	tail = nullptr;
	
	// convert line to list
	for (size_t i = 0; i < num.length(); i += digits) {
		
		new_node = new Node();
		if (i == 0) {
			digits = num.length() % m_digitsPerNode;
			if (digits == 0)
				digits = m_digitsPerNode;
		} else
			digits = m_digitsPerNode;
		
		new_node->num = std::stoll(num.substr(i, digits));
		Append(new_node);
	}
		
}


DoubleLinkedList::DoubleLinkedList(int digitsPerNode)
{
	if (digitsPerNode >=2 && digitsPerNode <= 8)
		m_digitsPerNode = digitsPerNode;
	else
		m_digitsPerNode = 2;
	
	tail = head = nullptr;
	remainder = 0;
}

 // copy construct
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& list)
{
	head = tail = nullptr;
	*this = list;
}


// clear all list elements
void DoubleLinkedList::Clear()
{
	Node * cur_node;
	
	// free all allocated memory 
	while (head != nullptr) {
		cur_node = head;
		head = head->next;
		delete cur_node;
	}
	
	head = tail = nullptr;
	remainder = 0;
}


// insert new node to the front of the list (as new head)
void DoubleLinkedList::InsertFront(Node* node)
{
	node->prev = nullptr; 
	if (head == nullptr) {
		tail = head = node;
		node->next = nullptr; 
	} else {
		head->prev = node;
		node->next = head;
		head = node;
	}
}
	
 // assignment consturct
DoubleLinkedList& DoubleLinkedList::operator = (const DoubleLinkedList& list)
{
	Node *cur_node, *new_node;
	
	// free all allocated memory 
	Clear();
	
	// copy and append all nodes from list
	cur_node = list.head;
	while (cur_node != nullptr) {
		new_node = new Node();
		new_node->num = cur_node->num;
		Append(new_node);
		cur_node = cur_node->next;
	}
	
	remainder = list.remainder;
	m_digitsPerNode = list.m_digitsPerNode;
	return *this;
}


DoubleLinkedList DoubleLinkedList::operator + (const DoubleLinkedList& list) const 
{
	DoubleLinkedList result(m_digitsPerNode);
	Node *node1, *node2, *new_node;
	
	long long num1, num2, res, base, carry;
	
	base = (long long) (pow(10, m_digitsPerNode) + 0.5);
	node1 = this->tail;
	node2 = list.tail;
	
	// loop through all nodes in poth lists
	carry = 0;
	while (node1 != nullptr || node2 != nullptr || carry > 0) {
	
		if (node1 != nullptr) {
			num1 = node1->num;
			node1 = node1->prev;
		} else {
			num1 = 0;
		}
		
		if (node2 != nullptr) {
			num2 = node2->num;
			node2 = node2->prev;
		} else {
			num2 = 0;
		}
		
		res = carry + num1 + num2;
		carry = res / base;
		res %= base;  
		
		new_node = new Node();
		new_node->num = res;
		
		// add  new node to the begin of result list
		result.InsertFront(new_node);
	}
		
	return result;
}

DoubleLinkedList DoubleLinkedList::operator * (const DoubleLinkedList& list) const
{
	DoubleLinkedList result(m_digitsPerNode);
	Node *node1, *node2, *new_node;
	
	long long num1, num2, res, base, carry;
	
	base = (long long) (pow(10, m_digitsPerNode) + 0.5);
	
	node2 = list.head;
	
	while (node2 != nullptr) {
		DoubleLinkedList partial_result(m_digitsPerNode);
		
		if (node2 != nullptr) {
			num2 = node2->num;
			node2 = node2->next;
		} else {
			num2 = 0;
		}
		
		// loop through all nodes in node1 lists
		node1 = this->tail;
		carry = 0;
		while (node1 != nullptr || carry > 0) {
	
			if (node1 != nullptr) {
				num1 = node1->num;
				node1 = node1->prev;
			} else {
				num1 = 0;
			}
		
			res = carry + num1 * num2;
			carry = res / base;
			res %= base;  
		
			new_node = new Node();
			new_node->prev = nullptr;
			new_node->num = res;
		
			// add  new node to the begin of result list
			partial_result.InsertFront(new_node);
		}
		
		// update result
		new_node = new Node();
		new_node->num = 0;
		result.Append(new_node);
		
		result = result + partial_result;
	}
	
	return result;
}
    
// optional
DoubleLinkedList DoubleLinkedList::operator - (const DoubleLinkedList& list) const
{
	DoubleLinkedList result(m_digitsPerNode);
	Node *node1, *node2, *new_node;
	
	long long num1, num2, res, base, borrow;
	
	base = (long long) (pow(10, m_digitsPerNode) + 0.5);
	node1 = this->tail;
	node2 = list.tail;
	
	// loop through all nodes in both lists
	borrow = 0;
	while (node1 != nullptr || node2 != nullptr || borrow > 0) {
	
		if (node1 != nullptr) {
			num1 = node1->num;
			node1 = node1->prev;
		} else {
			num1 = 0;
		}
		
		if (node2 != nullptr) {
			num2 = node2->num;
			node2 = node2->prev;
		} else {
			num2 = 0;
		}
		
		res = num1 - num2 - borrow;
		if ((node1 != nullptr || node2 != nullptr) && res < 0) {
			res = base + res;
			borrow = 1;
		} else {
			borrow = 0;
		}
			
		new_node = new Node();
		new_node->num = res;
		
		// add  new node to the begin of result list
		result.InsertFront(new_node);
		
	}
	
	// normalization (delete leading zero nodes)
	result.Normalize();
	return result;
}

// delete leading zero nodes from the list
void DoubleLinkedList::Normalize()
{
	Node * cur_node;
	
	while (head->next != nullptr && head->num == 0) {
		cur_node = head;
		head = head->next;
		head->prev = nullptr;
		delete cur_node;
	}
}


// returns number as long long
long long DoubleLinkedList::ToLongLong() const
{
	long long result, base;
	Node *cur_node;
	
	base = (long long) (pow(10, m_digitsPerNode) + 0.5);
	
	result = 0;
	cur_node = head;
	
	while (cur_node != nullptr)
	{
		result = result * base + cur_node->num;
		cur_node = cur_node->next;
	}
	
	return result;
}

// 10% extra
DoubleLinkedList DoubleLinkedList::operator / (const DoubleLinkedList& list) const
{
	DoubleLinkedList result(m_digitsPerNode);
	Node *node1, *new_node;
	
	long long base, part, list_ll;
	
	base = (long long) (pow(10, m_digitsPerNode) + 0.5);
	
	node1 = this->head;
	list_ll = list.ToLongLong();
	part = 0;
	while (node1 != nullptr){
		while (node1 != nullptr && part < list_ll)	{
			// shift result
			new_node = new Node();
			new_node->num = 0;
			result.Append(new_node);
			
			// append next dividend number to partial divident
			part = part * base + node1->num;
			node1 = node1->next;
		}
		
		if (part < list_ll)	{
			result.remainder = part;
			result.Normalize();
			return result;
		}
		
		// calculate last number of quotient
		result.tail->num = part / list_ll;
		
		// update partial dividend and remainder
		part -= list_ll * result.tail->num;
		result.remainder = part;
		
	}
	
	result.Normalize();
	return result;
}

const Node* DoubleLinkedList::GetHead() const
{
	return head;
}

const Node* DoubleLinkedList::GetTail() const
{
	return tail;
}

// append new node to the end of list
void DoubleLinkedList::Append(Node* node)
{
	if (head == nullptr) { // add the first node as new head
		tail = head = node;
		node->prev = nullptr;
	} else { // not first node as new tail
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	node->next = nullptr;
}

void DoubleLinkedList::Print() const
{
	Node *cur_node;

	// print all node values	
	cur_node = head;
	while (cur_node != nullptr) {
		if (cur_node != head) {
			std::cout << std::setw(this->m_digitsPerNode) << std::setfill('0');
		}
		std::cout << cur_node->num;
		cur_node = cur_node->next;
	}
	std::cout << std::setfill(' ');
	
	if (remainder != 0)
		std::cout << ",remainder=" << remainder;
}

