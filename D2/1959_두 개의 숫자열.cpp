#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1959_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int numberOfFirst, numberOfSecond;
		inputFile >> numberOfFirst >> numberOfSecond; // 3 ~ 20

		vector<int> first(numberOfFirst, 0);
		for (int i = 0; i < numberOfFirst; i++)
		{
			inputFile >> first[i];
		}

		vector<int> second(numberOfSecond, 0);
		for (int i = 0; i < numberOfSecond; i++)
		{
			inputFile >> second[i];
		}
		
		vector<int> smallBox, bigBox;
		if (numberOfFirst <= numberOfSecond)
		{
			smallBox = first;
			bigBox = second;
		}
		else
		{
			smallBox = second;
			bigBox = first;
		}

		vector<int> findMax;
		for (int move = 0; move < (bigBox.size() - smallBox.size() + 1); move++)
		{
			int sum = 0;
			for (int mulAdd = 0; mulAdd < smallBox.size(); mulAdd++)
			{
				sum += smallBox[mulAdd] * bigBox[mulAdd + move];
			}
			findMax.push_back(sum);
		}
		
		sort(findMax.begin(), findMax.end(), greater<>{});

		cout << "#" << testCase << " " << findMax[0] << endl;


	}

	return 0;
}