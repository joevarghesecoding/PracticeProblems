#include "Stack.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Testing first line\n";
	Stack a, b(2);
	
	/*a.push(3);
	a.push(4);*/

	cout << "\nPrintout stack a ";
	a.display(cout);
	cout << "\nPrintout stack b ";
	b.display(cout);


	return 0;
}

