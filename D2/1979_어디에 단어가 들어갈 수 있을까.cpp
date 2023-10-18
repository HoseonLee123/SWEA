#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1979_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int puzzleLength{ 0 }; // 5 ~ 15
		int wordLength{ 0 }; // 2 ~ puzzleLength
		inputFile >> puzzleLength >> wordLength;

		// Create a puzzle.
		vector<vector<int>> puzzle(puzzleLength, vector<int>(puzzleLength, 0));
		for (int i = 0; i < puzzleLength; i++)
		{
			for (int j = 0; j < puzzleLength; j++)
			{
				inputFile >> puzzle[i][j];
			}
		}

		int fit{ 0 };
		for (int i = 0; i < puzzleLength; i++)
		{
			for (int j = 0; j < puzzleLength; j++)
			{
				// Row check
				// Is there a space for the word?
				// 1. Does the word go out of the puzzle?
				// 2. The word is within the puzzle, but does the space to enter contain a black wall?
				bool isThereSpace{ true };
				if (j + wordLength - 1 >= puzzleLength)
					isThereSpace = false;
				else
				{
					for (int k = 0; k < wordLength; k++)
					{
						if (puzzle[i][j + k] == 0)
						{
							isThereSpace = false;
							break;
						}
					}

				}

				// Left check
				// 1. The left is out of the puzzle .
				// 2. The left is a black wall.
				bool isRightPlaceToStart{ false };
				if ((j - 1) == -1)
					isRightPlaceToStart = true;
				else if (puzzle[i][j - 1] == 0)
					isRightPlaceToStart = true;


				// Right check
				// The right is out of the puzzle.
				// The right is a black wall.
				if (isThereSpace && isRightPlaceToStart)
				{
					if (j + wordLength == puzzleLength)
					{
						++fit;
					}

					else if (puzzle[i][j + wordLength] == 0)
					{
						++fit;
					}
				}

				// Column check
				// Is there a space for the word?
				// 1. Does the word go out of the puzzle?
				// 2. The word is within the puzzle, but does the space to enter contain a black wall?
				isThereSpace = true;
				if (i + wordLength - 1 >= puzzleLength)
					isThereSpace = false;
				else
				{
					for (int k = 0; k < wordLength; k++)
					{
						if (puzzle[i + k][j] == 0)
						{
							isThereSpace = false;
							break;
						}
					}

				}

				// Upper check
				// 1. The upper is out of the puzzle.
				// 2. The upper is a black wall.
				isRightPlaceToStart = false;
				if ((i - 1) == -1)
					isRightPlaceToStart = true;
				else if (puzzle[i - 1][j] == 0)
					isRightPlaceToStart = true;


				// Bottom check
				// The bottom is out of the puzzle.
				// The bottom is a black wall.
				if (isThereSpace && isRightPlaceToStart)
				{
					if (i + wordLength == puzzleLength)
					{
						//cout << i << ", " << j << endl;
						++fit;
					}

					else if (puzzle[i + wordLength][j] == 0)
					{
						//cout << i << ", " << j << endl;
						++fit;
					}
				}
			}
		}

		cout << "#" << testCase << " " << fit << endl;


	}




	return 0;
}