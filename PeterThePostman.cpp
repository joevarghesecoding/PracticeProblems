/*Question: Peter the postman became bored one night and, to break the monotony of the night
shift, he carried out the following experiment with a row of mailboxes in the post
office. These mailboxes were numbered 1 through 150, and beginning with mailbox 2,
he opened the doors of all the even-numbered mailboxes, leaving the others closed.
Next, beginning with mailbox 3, he went to every third mail box, opening its door if it
were closed, and closing it if it were open. Then he repeated this procedure with every
fourth mailbox, then every fifth mailbox, and so on. When he finished, he was surprised
at the distribution of closed mailboxes. Write a program to determine which mailboxes
these were.
*/
#include <iostream>

using namespace std;

void counter(const int, int*);

int main()
{
	const int CAPACITY = 150;
	const int CAPACITY2 = 160;
	int openOrClose[CAPACITY2];
	int* openOrClosePtr = openOrClose;


	//first set all the mailboxes to closed
	for (int i = 0; i < CAPACITY + 1; i++)
	{
		*(openOrClosePtr + i) = 0;
	}

	//next, if the index modulus the iterator equals 0 (remainder is zero) then put a one in that value. else change the one to a 0.
	// for(int i = 2; i < CAPACITY + 1; i++) //divisor
	// {
	//   for(int j = 1; j < CAPACITY + 1; j++) //mailbox
	//   {
	//     if((j % i) == 0)
	//       {
	//         if(openOrClose[j] == 0)
	//            openOrClose[j] = 1;
	//        else if(openOrClose[j] == 1)
	//            openOrClose[j] = 0;
	//       }

	//   }
	// }

	counter(CAPACITY, openOrClosePtr);


	//	cout << "Its working upto now; the k for loop isn't working" << endl;
	for (int k = 1; k < CAPACITY + 1; k++)
	{
		//cout << "Its working upto now; the if statements are not working" << endl;
		if (openOrClose[k] == 0)
			cout << "The mailbox : " << k << " is Closed." << endl;
		else if (openOrClose[k] == 1)
			cout << "The mailbox : " << k << " is Open." << endl;
	}

	openOrClosePtr = 0;
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
