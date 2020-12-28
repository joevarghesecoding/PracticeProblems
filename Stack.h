//This is a practice Stack linked list.
//Errors may occur


#ifndef Stack_h
#define Stack_h

#include <iostream>

class Node {
public:
	int data;
	Node* next;
	Node() : data(0), next(0) {}
	Node(int d) : data(d), next(0) {} // testing this Node(int d, Node * link) : data(d), next(link) {}
}; 

typedef Node* NodePtr;

class Stack {
private:
	NodePtr head;

public:
	Stack();
	Stack(int d);
	Stack(Node* first);
	Stack(const Stack& a);
	~Stack();
	bool empty() const;
	void push(const int & a);
	void pop();
	auto top() const;
	void display(std::ostream & out) const;
	Stack& operator=(const Stack& a);
};

std::ostream& operator<<(std::ostream, const Stack& a);


#endif