#include "pch.h"

int main()
{
	int testCase;
	int T;
	cin >> T;

	for (testCase = 1; testCase <= T; ++testCase)
	{
		int sizeOfCluster;
		int sizeOfSwatter;
		cin >> sizeOfCluster; // 5 ~ 15
		cin >> sizeOfSwatter; // 2 ~ sizeOfCluster

		// Create files.
		vector<vector<int>> files(sizeOfCluster, vector<int>(sizeOfCluster, 0));
		for (int i = 0; i < files.size(); i++)
		{
			for (int j = 0; j < files[i].size(); j++)
			{
				cin >> files[i][j]; // <= 30
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