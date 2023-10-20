#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1954_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int size;
		inputFile >> size; // 1~10

		vector<vector<int>> snailMap(size, vector<int>(size, 0));

		int count = 1;
		int dirI[4] = { 0,1,0,-1 }; // right, down, left, up
		int dirJ[4] = { 1,0,-1,0 }; // right, down, left, up
		int dir = 0;
		int nowI = 0;
		int nowJ = 0;

		// Set the first count.
		snailMap[0][0] = count;
		++count;

		// Next i, j
		while (count <= (size * size))
		{
			int nextI = nowI + dirI[dir];
			int nextJ = nowJ + dirJ[dir];

			if ((nextI >= 0 && nextI < size) && (nextJ >= 0 && nextJ < size) && (snailMap[nextI][nextJ] == 0))
			{
				nowI = nextI;
				nowJ = nextJ;
				snailMap[nowI][nowJ] = count;
				++count;
			}
			else // Change the direction.
			{
				dir = (dir + 1) % 4;
			}
		}

		cout << "#" << testCase << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (size <= 3)
				{
					cout << snailMap[i][j] << " ";
				}
				else if (size <= 9)
				{
					if(snailMap[i][j] <= 9)
						cout << " " << snailMap[i][j] << " ";
					else
						cout << snailMap[i][j] << " ";
				}
				else
				{
					if (snailMap[i][j] <= 9)
						cout << "  " << snailMap[i][j] << " ";
					else if (snailMap[i][j] <= 99)
						cout << " " << snailMap[i][j] << " ";
					else
						cout << snailMap[i][j] << " ";
				}
			}
			cout << endl;
		}
	}

	return 0;
}