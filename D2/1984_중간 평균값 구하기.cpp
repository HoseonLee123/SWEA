#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1984_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		vector<int> inputs(10, 0);
		for (int i = 0; i < 10; i++)
		{
			inputFile >> inputs[i];
		}

		sort(inputs.begin(), inputs.end());

		double sum{ 0.0 };
		for (int i = 0; i < 10; i++)
		{
			if (i == 0 || i == 9)
				continue;
			else
				sum += inputs[i];
		}

		double average = round(sum / 8);

		cout << "#" << testCase << " " << average << endl;
	}




	return 0;
}