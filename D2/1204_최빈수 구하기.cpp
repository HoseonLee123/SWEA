#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1204_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		[[maybe_unused]] int numTestCase;
		inputFile >> numTestCase;

		vector<pair<int, int>> info; // frequency, score 0~100
		for (int i = 0; i < 101; i++)
		{
			info.push_back(make_pair(0, i));
		}

		for (int i = 0; i < 1000; i++)
		{
			int score;
			inputFile >> score;
			++info[score].first;
		}

		sort(info.begin(), info.end(), greater<>{});

		cout << "#" << testCase << " " << info[0].second << endl;
	}


	return 0;
}