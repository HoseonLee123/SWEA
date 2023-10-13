#include "pch.h"


int main()
{
	ifstream inputFile;
	inputFile.open("./input/2005_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int n;
		inputFile >> n;

		// Solution 1: use 2-dimensional vector.
		vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));

		map[1][1] = 1;

		for (int i = 2; i < n + 1; i++)
		{
			for (int j = 1; j < i + 1; j++)
			{
				map[i][j] = map[i - 1][j - 1] + map[i - 1][j];
			}
		}


		cout << "#" << testCase << endl;
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < i + 1; j++)
			{
				cout << map[i][j] << " ";
			}
			cout << endl;
		}


		//// Solution2: use 1-dimensional vector. Good try~
		//// Create pascal triangle.
		//// 0 is to create the next level.
		////      0 1 0
		//// 0 (0+1) (1+0) 0
		//// ...
		//// Level 1
		//vector<int> pascalTriangle;
		//pascalTriangle.push_back(0);
		//pascalTriangle.push_back(1);
		//pascalTriangle.push_back(0);

		//// Level 2 ~ N
		//int startIndex = 0;
		//for (int level = 2; level <= N; level++)
		//{
		//	pascalTriangle.push_back(0);  

		//	for (int j = startIndex; j < (startIndex + level); j++)
		//	{
		//		pascalTriangle.push_back(pascalTriangle[j] + pascalTriangle[j + 1]);
		//	}

		//	pascalTriangle.push_back(0);

		//	startIndex = startIndex + level + 1;
		//}

		//// Print pascal triangle without 0.
		//cout << "#" << testCase << endl;

		//int goNextLevel = 2;
		//int level = 1;
		//for (int i = 1; i < pascalTriangle.size(); i = i + goNextLevel)
		//{
		//	int printingIndex = i;
		//	for (int goNextIndex = 1; goNextIndex <= level; ++goNextIndex)
		//	{
		//		cout << pascalTriangle[printingIndex] << " ";
		//		++printingIndex;
		//	}

		//	++level;
		//	++goNextLevel;
		//	cout << endl;
		//}

	}

	return 0;
}