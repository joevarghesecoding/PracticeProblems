#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>

class Node {											 //public class Node inside the private class LinkedList
	public:
		int data;
		Node* next;
		Node() : data(0), next(0) {};
		Node(int d) : data(d), next(0) {};
	};


class LinkedList {
private:	
	//class Node {											 //public class Node inside the private class LinkedList
	//public:
	//	int data;
	//	Node* next;
	//	Node(int d) : data(d), next(0) {};
	//};
	Node* first;
	int count;
	
public:
	LinkedList();
	LinkedList(int data);
	LinkedList(const LinkedList& a);						//copy constructor
	~LinkedList();										    //Destructor

	void insert(const Node* a, int pos);					 //Inserting a value at a pos
	void traverse();										 //going through a list 
	void display(std::ostream & out) const;									 //displays the values in the list as a debugging measure
	void delNode(int pos);									 //Deletes at a position
	const LinkedList& operator=(const LinkedList& rightHandSide);  //Overloaded assignment operator
	
};

std::ostream& operator<<(std::ostream& out, const LinkedList& a);


#endif