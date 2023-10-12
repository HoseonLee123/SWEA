#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/2001_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int testCase;
	int T;
	inputFile >> T;

	for (testCase = 1; testCase <= T; ++testCase)
	{
		int sizeOfCluster;
		int sizeOfSwatter;
		inputFile >> sizeOfCluster; // 5 ~ 15
		inputFile >> sizeOfSwatter; // 2 ~ sizeOfCluster

		// Create files.
		vector<vector<int>> files(sizeOfCluster, vector<int>(sizeOfCluster, 0));
		for (int i = 0; i < files.size(); i++)
		{
			for (int j = 0; j < files[i].size(); j++)
			{
				inputFile >> files[i][j]; // <= 30
			}
		}

		// Catch files.
		vector<int> killInformation;

		for (int i = 0; i < (sizeOfCluster - sizeOfSwatter + 1); i++)
		{
			for (int j = 0; j < (sizeOfCluster - sizeOfSwatter + 1); j++)
			{
				int killed{ 0 };
				for (int k = 0; k < sizeOfSwatter; k++)
				{
					for (int w = 0; w < sizeOfSwatter; w++)
					{
						killed += files[i + k][j + w];
					}
				}
				killInformation.push_back(killed);
			}
		}

		sort(killInformation.begin(), killInformation.end(), greater<>{});

		cout << "#" << testCase << " " << killInformation[0] << endl;
		
	}



	return 0;
}