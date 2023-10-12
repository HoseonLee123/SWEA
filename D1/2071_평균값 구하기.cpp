#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/2071_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int test_case;
	int T;
	inputFile >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int numbers[10]{};
		for (int i = 0; i < 10; i++)
		{
			inputFile >> numbers[i];
		}

		int sum{};
		for (int i = 0; i < 10; i++)
		{
			sum += numbers[i];
		}

		int average{};
		// Round to the first decimal place.
		if (sum % 10 >= 5)
			average = sum / 10 + 1;
		else
			average = sum / 10;

		cout << "#" << test_case << " " << average << endl;
	}
	return 0;
}