#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/2070_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int testCase;
	int T;
	inputFile >> T;

	for (testCase = 1; testCase <= T; ++testCase)
	{
		int num1;
		int num2;
		inputFile >> num1;
		inputFile >> num2;

		const char* result{};
		if (num1 > num2)
			result = ">";
		else if (num1 < num2)
			result = "<";
		else
			result = "=";

		cout << "#" << testCase << " " << result << endl;
	}



	return 0;
}