#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1986_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int testCase;
	int T;
	inputFile >> T;

	for (testCase = 1; testCase <= T; ++testCase)
	{
		int num;
		inputFile >> num;

		int sum{ 0 };
		for (int i = 1; i <= num; i++)
		{
			if (i % 2 == 1)
				sum += i;
			else
				sum -= i;
		}

		cout << "#" << testCase << " " << sum << endl;

	}

	inputFile.close();

	return 0;
}