#include "Stack.h"

Stack::Stack()
{
	//an empty default initialized stack object will have a head pointing to null
	head = 0;
}

Stack::Stack(int d)
{
	head->data = d;
	//head->next = 0;
}

Stack::Stack(Node* a)
{
	//a constructor with a node argument makes a new node with its data and puts it in head.
	head = new Node(a->data);
	head->next = a->next;
}

Stack::Stack(const Stack& a)
{
	//pointer for a for treversal
	NodePtr aCur = a.head;
	//poitner for this for treversal
	NodePtr tCur = head;
	//assign a.head to this
	head = a.head;
	while (aCur)
	{
		//deep copy and treversal
		tCur->next = new Node(a.head->next->data);
		tCur = tCur->next;
		aCur = aCur->next;
	}
}

Stack::~Stack()
{
	//assign an iterator pointer to this head value
	NodePtr tCur = head;
	//dont burn bridges before you cross them, need this pointer to hold the bridge
	NodePtr nextCur;

	while (tCur != 0)
	{
		//copy the next step before deleting, or memory is lost
		nextCur = tCur->next;
		//delete the step
		delete tCur;
		//iterate, put the next step in line
		tCur = nextCur;
	}
}

//returns true if the top or head value is empty
bool Stack::empty() const
{
	return head == 0;
}

//pushes value to the head
void Stack::push(const int & a) 
{
	//make a new pointer to hold the current head
	NodePtr newPtr = head;
	//push the new value to the current head
	head = new Node(a); //testing something, check definitions
	//link the old head to this new one
	head->next = newPtr;
}

void Stack::pop()
{
	//don't burn bridges before you cross them
	NodePtr nextHead = head->next;
	delete head;
	head = nextHead;
}

auto Stack::top() const //testing this
{
	return head->data;
}

void Stack::display(std::ostream& out) const
{
	NodePtr hPtr = head;
	while (hPtr)
	{
		out << head->data;
	}
}

Stack& Stack::operator=(const Stack& a)
{
	if (this != &a)
	{
		NodePtr tCur = head;
		while (tCur)
		{
			this->pop();
		}
		head = a.head;
		NodePtr aCur = a.head;
		while (aCur)
		{
			NodePtr tCur = head;
			//same code from copy constructor for deep copy
			tCur->next = new Node(a.head->next->data);
			tCur = tCur->next;
			aCur = aCur->next;
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream out, const Stack& a)
{
	a.display(out);
	return out;
}