#include "pch.h"

bool LineCompare(vector<vector<int>> sudoku, vector<int> comparisonSudoku)
{
	for (int i = 0; i < 9; i++)
	{
		vector<int> targetSudoku(9, 0);
		for (int j = 0; j < 9; j++)
		{
			targetSudoku[j] = sudoku[i][j];
		}

		sort(targetSudoku.begin(), targetSudoku.end());

		if (targetSudoku != comparisonSudoku)
			return false;
	}

	return true;
}

bool SquareCompare(vector<vector<int>> sudoku, vector<int> comparisonSudoku)
{
	for (int startI = 0; startI < 9; startI = startI + 3)
	{
		for (int startJ = 0; startJ < 9; startJ = startJ + 3)
		{
			vector<int> targetSudoku;
			for (int repI = 0; repI < 3; repI++)
			{
				for (int repJ = 0; repJ < 3; repJ++)
				{
					targetSudoku.push_back(sudoku[startI + repI][startJ + repJ]);
				}
			}
			sort(targetSudoku.begin(), targetSudoku.end());

			if (targetSudoku != comparisonSudoku)
				return false;
		}
	}

	return true;
}



int main()
{
	ifstream inputFile;
	inputFile.open("./input/1974_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		vector<vector<int>> sudoku(9, vector<int>(9, 0));
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				inputFile >> sudoku[i][j]; // 1 ~ 9
			}
		}

		vector<vector<int>> transposedSudoku(9, vector<int>(9, 0));
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				transposedSudoku[i][j] = sudoku[j][i];
			}
		}

		vector<int> comparisonSudoku = { 1,2,3,4,5,6,7,8,9 };

		bool rowCheck = LineCompare(sudoku, comparisonSudoku);
		bool columnCheck = LineCompare(transposedSudoku, comparisonSudoku);
		bool squareCheck = SquareCompare(sudoku,comparisonSudoku);

		bool answer{};
		if (rowCheck + columnCheck + squareCheck == 3)
			answer = true;
		else
			answer = false;

		cout << "#" << testCase << " " << answer << endl;

	}




	return 0;
}