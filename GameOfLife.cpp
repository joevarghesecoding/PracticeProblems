/************************************************************************
* GameOfLife.cpp
* Jyothish Joe Varghese
* Last Edit: 9/14/2020
* 
The game of Life, invented by the mathematician John H. Conway, is intended to model
life in a society of organisms. Consider a rectangular array of cells, each of which may
contain an organism. If the array is viewed as extending indefinitely in both directions,
then each cell has eight neighbors, the eight cells surrounding it. In each generation,
births and deaths occur according to the following rules:
• An organism is born in any empty cell having exactly three neighbors.
• An organism dies from isolation if it has fewer than two neighbors.
• An organism dies from overcrowding if it has more than three neighbors.
• All other organisms survive.

Write a program to play the game of Life and investigate the patterns produced by various
initial configurations. Some configurations die off rather rapidly; others repeat after a
certain number of generations; others change shape and size and may move across the
array; and still others may produce "gliders" that detach themselves from the society and
sail off into space.
**************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//stuck at getting 4 corners all to appear 0

int main()
{
	unsigned seed = time(0);
	srand(seed);
	const int CAPACITY = 20;
	int rectArray[CAPACITY][CAPACITY];
	char cell = '.';
	
	

	// && !rectArray[CAPACITY-1][j] && !rectArray[i][CAPACITY -1]
	//insert random values
	for (int i = 1; i <= CAPACITY - 1 ; i++)
	{
		for (int j = 1; j <= CAPACITY - 1; j++)
		{
			int y = (rand() % 2) + 0;
			if (y == 1)
			{
				rectArray[i][j] = 1;
			}
			else if (y == 0)
			{
				rectArray[i][j] = 0;
			}
		}
	}

	//x first rows and columns have 0
	for (int i = 0; i < CAPACITY - 1; i++)
	{
		for (int j = 0; j < CAPACITY - 1; j++)
		{
			rectArray[0][j] = 0;
			rectArray[i][0] = 0;
			rectArray[CAPACITY - 1][j] = 0;
			rectArray[i][CAPACITY - 1] = 0;
		}
	}

	//rules
	for (int i = 1; i < CAPACITY - 1; i++)
	{
		for (int j = 1; j < CAPACITY - 1; j++)
		{
			if (rectArray[i][j] == 0)
			{
				
			}
		}
	}

	//print
	for (int i = 0; i < CAPACITY - 1; i++)
	{
		for (int j = 0; j < CAPACITY - 1; j++)
		{
			cout << rectArray[i][j];
			if (j % CAPACITY == 0)
				cout << endl;
		}
	}


	return 0;
}