#include "pch.h"

int Count(vector<vector<int>> puzzle, int wordLength)
{
	int numberOfperfectPlaces = 0;
	int numberOfEmptySpaces = 0;
	for (int i = 0; i < puzzle.size(); i++)
	{
		for (int j = 0; j < puzzle.size(); j++)
		{
			if (puzzle[i][j] == 1)
				++numberOfEmptySpaces;
			else // puzzle[i][j] == 0
			{
				if (numberOfEmptySpaces == wordLength)
				{
					++numberOfperfectPlaces;
				}

				numberOfEmptySpaces = 0;
			}
		}
	}

	return numberOfperfectPlaces;
}



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

		// Create a puzzle with 0 padding.
		vector<vector<int>> puzzle(puzzleLength + 1, vector<int>(puzzleLength + 1, 0));
		for (int i = 0; i < puzzleLength; i++)
		{
			for (int j = 0; j < puzzleLength; j++)
			{
				inputFile >> puzzle[i][j];
			}
		}

		// Create a transposed puzzle for vertical calculation.
		vector<vector<int>> transposedPuzzle(puzzle.size(), vector<int>(puzzle.size(), 0));
		for (int i = 0; i < puzzle.size(); i++)
		{
			for (int j = 0; j < puzzle.size(); j++)
			{
				transposedPuzzle[i][j] = puzzle[j][i];
			}
		}

		int answer = Count(puzzle, wordLength) + Count(transposedPuzzle, wordLength);

		cout << "#" << testCase << " " << answer << endl;
	}




	return 0;
}