#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/2046_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int input;
	inputFile >> input;

	for (int i = 0; i < input; i++)
	{
		cout << "#";
	}



	return 0;
}