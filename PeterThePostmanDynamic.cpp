/*
Change the peterthepostman.cpp into a dynamically allocated array
*/

#include <iostream>

using namespace std;

void counter(const int, int*);

int main()
{
	int capacity;
	cout << "How big do you want the array to be? " << endl;
	cin >> capacity;
	int* openOrClose = new int[capacity];
	//int* openOrClosePtr = openOrClose;


	//first set all the mailboxes to closed
	for (int i = 0; i < capacity + 1; i++)
	{
		*(openOrClose + i) = 0;
	}


	counter(capacity, openOrClose);


	//	cout << "Its working upto now; the k for loop isn't working" << endl;
	for (int k = 1; k < capacity + 1; k++)
	{
		//cout << "Its working upto now; the if statements are not working" << endl;
		if (openOrClose[k] == 0)
			cout << "The mailbox : " << k << " is Closed." << endl;
		else if (openOrClose[k] == 1)
			cout << "The mailbox : " << k << " is Open." << endl;
	}

	openOrClose = 0;
	return 0;
}

void counter(const int CAPACITY, int* i)
{
	for (int k = 2; k < CAPACITY + 1; k++) //divisor
	{
		for (int j = 1; j < CAPACITY + 1; j++) //mailbox
		{
			if ((j % k) == 0)
			{
				if (i[j] == 0)
					i[j] = 1;
				else if (i[j] == 1)
					i[j] = 0;
			}

		}
	}

}
