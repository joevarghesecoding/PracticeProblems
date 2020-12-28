/* Chapter 5 Question 4
Write a program that reads a text file and counts the characters in each line. The program should display the line
number and the length of the shortest and longest lines in the file as well as the average number of characters per line*/

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int main()
{
	ifstream myFile;
	string fileName;
	int shortest = INT_MAX,
		longest = 0;
	char ch;
	int totalCount = 0;
	int lineCount = 1;
	int longestLine = 1;
	int shortestLine = 1;
	int countPerLine = 0;
	double average;


	cout << "Enter the name of the file: ";
	cin >> fileName;
	myFile.open(fileName.data());
	assert(myFile.is_open());

	for(;;) //WHITE SPACE WAS SKIPPING THE \n CHAR
	{
		myFile >> noskipws >> ch;
		totalCount++;
		countPerLine++;
		if (ch == '\n')
		{
			if (countPerLine < shortest)
			{
				shortest = countPerLine;
				shortestLine = lineCount;
			}
			if (countPerLine > longest)
			{
				longest = countPerLine;
				longestLine = lineCount;
			}
			lineCount++;
			countPerLine = 0;
		}
		if (myFile.eof()) //Stops checking at the last line, so I added it again.
		{
			if (countPerLine < shortest)
			{
				shortest = countPerLine;
				shortestLine = lineCount;
			}
			if (countPerLine > longest)
			{
				longest = countPerLine;
				longestLine = lineCount;
			}
			break;
		}
	}

	myFile.close();

	cout << "Total number of characters were: " << totalCount << endl;
	cout << "Total number of lines were: " << lineCount << endl;
	cout << "Last line count was: " << countPerLine << endl;
	cout << "The shortest line was line: " << shortestLine << " and the count was: " << shortest << endl;
	cout << "The longest line was line: " << longestLine << " and the count was: " << longest << endl;
	cout << "The average number of characters per line was: " << (double)(totalCount / lineCount) << endl;

	return 0;
}