#include "pch.h"

bool CheckRook(vector<vector<int>> Chessboard)
{
	bool Check = true;
	int AllLineSum = 0;

	// All rooks cannot attack each other.
	for (int i = 0; i < Chessboard.size(); i++)
	{
		int OneLineSum = 0;
		for (int j = 0; j < Chessboard[i].size(); j++)
		{
			OneLineSum += Chessboard[i][j];
		}

		if (OneLineSum > 1)
		{
			Check = false;
			break;
		}

		AllLineSum += OneLineSum;
	}

	// 8 rooks.
	if (AllLineSum != 8)
		Check = false;

	return Check;
}

int main()
{
	ifstream InputFile;
	InputFile.open("./input/15612_input.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;

	for (int TestCase = 1; TestCase <= TotalTestCase; ++TestCase)
	{
		vector<vector<int>> Chessboard(8, vector<int>(8, 0));

		for (int i = 0; i < 8; i++)
		{
			string OneLine;
			InputFile >> OneLine;

			int IsThereRook = 0;
			for (int j = 0; j < OneLine.size(); j++)
			{
				if (OneLine[j] == '.')
				{
					IsThereRook = 0;
				}
				else
				{
					IsThereRook = 1;
				}
				Chessboard[i][j] = IsThereRook;
			}
		}

		vector<vector<int>> TransposedChessboard(8, vector<int>(8, 0));
		for (int i = 0; i < TransposedChessboard.size(); i++)
		{
			for (int j = 0; j < TransposedChessboard[i].size(); j++)
			{
				TransposedChessboard[i][j] = Chessboard[j][i];
			}
		}

		// Check
		string answer;
		bool HorizontalCheck = CheckRook(Chessboard);
		if (HorizontalCheck)
		{
			bool VerticalCheck = CheckRook(TransposedChessboard);
			if (VerticalCheck)
			{
				answer = "yes";
			}
			else
			{
				answer = "no";
			}
		}
		else
		{
			answer = "no";
		}

		cout << "#" << TestCase << " " << answer << endl;
	}

	return 0;
}