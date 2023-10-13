#include "pch.h"


int main()
{
	ifstream inputFile;
	inputFile.open("./input/1859_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int testCase;
	int T;
	inputFile >> T;

	for (testCase = 1; testCase <= T; ++testCase)
	{


	}

	return 0;
}