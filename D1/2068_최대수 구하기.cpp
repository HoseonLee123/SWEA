#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/2068_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int testCase;
	int T;
	inputFile >> T;

	for (testCase = 1; testCase <= T; ++testCase)
	{
		vector<int> input(10,0);

		for (int i = 0; i < 10; i++)
		{
			inputFile >> input[i];
		}

		sort(input.begin(), input.end(), greater<>{});

		cout << "#" << testCase << " " << input[0] << endl;
	}



	return 0;
}