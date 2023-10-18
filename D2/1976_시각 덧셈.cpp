#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1976_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int numberOfInputs = 4;
		vector<int> inputs(numberOfInputs, 0);
		for (int i = 0; i < numberOfInputs; i++)
		{
			inputFile >> inputs[i];
		}

		int hour = inputs[0] + inputs[2]; // 1 ~ 12
		int minute = inputs[1] + inputs[3]; // 0 ~ 59

		if (minute >= 60)
		{
			++hour;
			minute -= 60;
		}

		if (hour >= 13)
		{
			hour -= 12;
		}


		cout << "#" << testCase << " " << hour << " " << minute << endl;
	}




	return 0;
}