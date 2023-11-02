#include "pch.h"

int main()
{
	ifstream InputFile;
	InputFile.open("./input/2805_input.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;


	int TotalTestCase;
	InputFile >> TotalTestCase;

	for (int TestCase = 1; TestCase <= TotalTestCase; ++TestCase)
	{
		int FarmSize; // 1 ~ 49, odd number.
		InputFile >> FarmSize;

		vector<vector<int>> FarmCropsValue(FarmSize, vector<int>(FarmSize, 0));

		for (int i = 0; i < FarmSize; i++)
		{
			string OneLine;
			InputFile >> OneLine;
			for (int j = 0; j < FarmSize; j++)
			{
				FarmCropsValue[i][j] = (OneLine[j] - 48);
			}
		}

		int AllValue = 0;
		int StartCol = FarmSize / 2;
		int EndCol = FarmSize / 2;
		for (int Row = 0; Row < FarmSize; Row++)
		{
			for (int Col = StartCol; Col <= EndCol; Col++)
			{
				AllValue += FarmCropsValue[Row][Col];
			}

			if (Row < FarmSize / 2)
			{
				StartCol -= 1;
				EndCol += 1;
			}
			else
			{
				StartCol += 1;
				EndCol -= 1;
			}
		}

		cout << "#" << TestCase << " " << AllValue << endl;
	}

	return 0;
}