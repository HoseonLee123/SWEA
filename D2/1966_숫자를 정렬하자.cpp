#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1966_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int length;
		inputFile >> length;

		vector<int> inputs(length, 0);
		for (int i = 0; i < length; i++)
		{
			inputFile >> inputs[i];
		}

		sort(inputs.begin(), inputs.end());

		cout << "#" << testCase << " ";
		for (int element : inputs)
		{
			cout << element << " ";
		}
		cout << endl;
	}

	return 0;
}