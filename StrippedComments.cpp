/*Chapter 5 problem 7
Write a program that reads a file containing a C++ program and produces a file with all
comments stripped from the program.*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using namespace std;

int main()
{
	ifstream myFile;
	string inFileName("midterm1.txt"), outFileName("outfile5-7.txt");
	ofstream outFile;
	char ch1, ch2;

	myFile.open(inFileName.data());
	outFile.open(outFileName.data());
	assert(myFile.is_open());
	assert(outFile.is_open());

	cout << "process started" << endl;

	while (!myFile.eof())
	{
		string line;
		myFile >> noskipws >> ch1;
		//cout << ch1;
		if (ch1 == '/')
		{
			getline(myFile, line);
			outFile << '/' << line;
			if (line.substr(0,1).find("/*"))
			{
				while (!line.find("*/"))
				{
					getline(myFile, line);
					outFile << line;
				}
			}
			if (line.find('\n'))
				outFile << endl;		
		}
	}

	myFile.close();
	outFile.close();



	return 0;
}
