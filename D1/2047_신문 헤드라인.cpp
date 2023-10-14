#include "pch.h"


int main()
{
	ifstream inputFile;
	inputFile.open("./input/2047_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	string input;
	inputFile >> input;

	for (int i = 0; i < input.size(); i++)
	{
		input[i] = toupper(input[i]);
	}

	cout << input << endl;


	return 0;
}