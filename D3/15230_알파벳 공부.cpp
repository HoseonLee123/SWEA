#include "pch.h"

int main()
{
	ifstream InputFile;
	InputFile.open("./input/15230_input.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;

	for (int TestCase = 1; TestCase <= TotalTestCase; ++TestCase)
	{
		string AllAlphabets = "abcdefghijklmnopqrstuvwxyz";
		
		string InputAlphabets;
		InputFile >> InputAlphabets;

		int IsSameCount = 0;
		for (int i = 0; i < InputAlphabets.size(); i++)
		{
			if (InputAlphabets[i] == AllAlphabets[i])
				IsSameCount++;
			else
				break;
		}

		cout << "#" << TestCase << " " << IsSameCount << endl;
	}

	return 0;
}