#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1285_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int numberOfPerson;
		inputFile >> numberOfPerson;

		vector<int> records;
		for (int i = 0; i < numberOfPerson; i++)
		{
			int temp;
			inputFile >> temp;
			records.push_back(abs(temp));
		}

		sort(records.begin(), records.end());

		int bestRecord = records[0];
		int numberOfBestRecord = 1;
		for (int i = 1; i < numberOfPerson; i++)
		{
			if (records[i] == bestRecord)
				++numberOfBestRecord;
			else
				break;
		}
		
		cout << "#" << testCase << " " << bestRecord << " " << numberOfBestRecord << endl;

	}


	return 0;
}