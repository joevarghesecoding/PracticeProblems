#include "LinkedList.h"

LinkedList::LinkedList()
{
	count = 0;
	first = 0;
}

LinkedList::LinkedList(int data)
{
	count = 1;
	first = new Node(data);
}

LinkedList::LinkedList(const LinkedList& a)
{
	////make a temperory node with the data value of a
	//Node* tmp = new Node(a.first->data);
	////put this value in the first
	//first = tmp;
	
	first = new Node(a.first->data); // Shortened, don't need a tmp value here
	
	//update count
	count = a.count;
	//make a node pointer pointing to this object's first (for iteration)
	Node* current = first;	

	////make another pointer pointing to the copy object's first (Preserve the first link)
	//Node* aFirst = a.first;
	////make a pointer pointing to the copy object's first pointer (for iteration)
	//Node* aCurrentPtr = aFirst;
	
	//make a pointer pointing to the copy object's first pointer (for iteration) ------ SHORTENED, dont need to preserve
	Node* aCurrentPtr = a.first;
	//traverse loop
	while (aCurrentPtr->next != 0) //testing with 0, TRY NULL NEXT----- 0 WORKS
	{
		//make a new node for the next copy object's data and put it in THIS object's next
		current->next = new Node(aCurrentPtr->next->data);
		//iterate to the next pointer
		aCurrentPtr = aCurrentPtr->next;
		//iterate THIS object to the next
		current = current->next;
	}

	
}

LinkedList::~LinkedList()
{
	delete[] first;
}

void LinkedList::insert(const Node* a, int pos)
{
	int i = 0;
	//int counter = pos;

	if (pos > count || pos < 0) return;
	
	if (pos == 0)
	{
		Node* cur = new Node(a->data);
		cur->next = first;
		first = cur;
	}
	
	else 
	{
		Node* ptr = first;
		while (i <= pos)
		{
			ptr = ptr->next;
			i++;
			if (i == pos)
			{
				//New pointer to a Node object to hold value from given a in parameter
				Node* cur = new Node(a->data);
				//point the next of the newly made object with the next of the prev pointer (This is the long line)
				cur->next = ptr->next;
				//point the prev pointer's next to the new object which makes the inserting official
				ptr->next = cur;
			}
		}
	}
	count++;
}

void LinkedList::traverse()
{
	Node* ptr = first;
	while (ptr)
	{
		ptr = ptr->next;
	}
}

void LinkedList::delNode(int pos)
{
	Node* ptr = first;
	int i = 0;
	if (pos > count || pos < 0) return;

	if (pos == 0)
	{
		first = ptr->next;
	}
	while (i <= pos)
	{
		ptr = ptr->next;
		++i;
		if (i == pos)
		{
			Node* cur = ptr->next;
			ptr->next = cur->next;
			delete cur;
		}
	}
	count--;
}
void LinkedList::display(std::ostream & out) const
{
	Node* ptr = first;
	while (ptr)
	{
		out << ptr->data;
		out << " , ";
		ptr = ptr->next;
	}
	out << std::endl;
	out << "with count " << count;
}

const LinkedList & LinkedList::operator=(const LinkedList& rightHandSide)
{
	if (this != &rightHandSide)
	{
		//delete anything in the original first
		delete[] first;
		//make the count equal to the rightHandSide
		count = rightHandSide.count;
		//make the first nodes equal value
		first = new Node(rightHandSide.first->data);
		//Node pointer of righthandside to iterate
		Node* rightPtr = rightHandSide.first;
		//Node pointer of lefthandside to iterate
		Node* leftPtr = first;

		while (rightPtr) //Testing to see if this works ----- THIS WORKS!!!!
		{
			//add a new Node with the value of the righthandside
			leftPtr->next = new Node(rightPtr->data);
			//iterate righthand side
			rightPtr = rightPtr->next;
			//iterate lefthandside
			leftPtr = leftPtr->next;
		}

		/*while (ptr != 0) {
			first->next = new Node(ptr->next->data);
			ptr = ptr->next;
			count++;
		}*/
	}
	return *this;
}

std::ostream& operator<<(std::ostream& out, const LinkedList& a)
{
	a.display(out);
	return out;
}