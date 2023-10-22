#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1946_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int numberOfZippedAlphabets;
		inputFile >> numberOfZippedAlphabets; // 1~10

		cout << "#" << testCase << endl;

		int nextLineFlag = 0;
		for (int i = 0; i < numberOfZippedAlphabets; i++)
		{
			string alphabet;
			int numberOfAlphabet;
			inputFile >> alphabet >> numberOfAlphabet; // A~Z, 1~20

			for (int i = 0; i < numberOfAlphabet; i++)
			{
				cout << alphabet;
				
				++nextLineFlag;

				if ((nextLineFlag % 10) == 0)
					cout << endl;
			}
		}

		cout << endl;
	}

	return 0;
}