#include "pch.h"

int main()
{
	ifstream InputFile;
	InputFile.open("./input/16910_input.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;

	for (int TestCase = 1; TestCase <= TotalTestCase; ++TestCase)
	{
		int Radius;
		InputFile >> Radius; // 1 ~ 200

		int NumberOfGridPoint = Radius * 4 + 1;
		for (int X = 1; X <= Radius - 1; X++)
		{
			for (int Y = 1; Y <= Radius - 1; Y++)
			{
				if (X * X + Y * Y <= Radius * Radius)
					NumberOfGridPoint = NumberOfGridPoint + 4;
			}
		}

		cout << "#" << TestCase << " " << NumberOfGridPoint << endl;
	}

	return 0;
}