#include "LinkedList.h"
#include <iostream>

using namespace std;

void print(LinkedList a)
{
	cout << a << endl;
}
int main()
{
	LinkedList a(5);
	LinkedList b(a);

	cout << "A is ";
	a.display(cout);
	cout << endl;

	cout << "Testing copy constructor\n";
	cout << "B is ";
	b.display(cout);
	cout << endl;

	Node * c = new Node(10);
	b.insert(c, 0);
	Node* d = new Node(15);
	b.insert(d, 1);
	Node* e = new Node(12);
	b.insert(e, 2);
	Node* f = new Node(16);
	b.insert(f, 3);

	/*cout << "With C and D its ";
	b.display(cout);
	cout << endl;*/

	cout << "Adding E in between C and D its ";
	b.display(cout);
	cout << endl;

	cout << "Deleting" << endl;
	b.delNode(3);
	b.display(cout);
	cout << endl;

	cout << "adding 20\n";
	Node* g = new Node(20);
	b.insert(g, 3);
	
	cout << "Copy constructor test with more nodes\n";
	LinkedList z (b);
	z.display(cout);
	cout << endl;

	cout << "DEEP COPY TEST\n";
	Node* h = new Node(30);
	z.insert(h, 4);
	cout << "Z is now: ";
	z.display(cout);
	cout << "\nB is still: ";
	b.display(cout);

	cout << "Assignment operator test\n";
	LinkedList y = z;
	cout << "Y is now: ";
	y.display(cout);

	cout << "\nIs assignment operator a deep copier?\n";
	Node* j = new Node(40);
	y.insert(j, 5);
	cout << "Z is still: ";
	z.display(cout);
	cout << "\nY is now: ";
	y.display(cout);


	
	return 0;
}