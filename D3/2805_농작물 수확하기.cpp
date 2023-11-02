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
		int Middle = FarmSize / 2;
		for (int Row = 0; Row < FarmSize; Row++)
		{
			if (Row <= Middle)
			{
				for (int Col = (Middle - Row); Col < (Middle + Row) + 1; Col++)
				{
					AllValue += FarmCropsValue[Row][Col];
				}
			}
			else
			{
				for (int Col = (Row - Middle); Col < (FarmSize - (Row - Middle)); Col++)
				{
					AllValue += FarmCropsValue[Row][Col];
				}
			}
		}


		cout << "#" << TestCase << " " << AllValue << endl;
	}

	return 0;
}