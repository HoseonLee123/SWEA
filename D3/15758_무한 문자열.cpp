#include "pch.h"

int main()
{
	ifstream InputFile;
	InputFile.open("./input/15758_input.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;

	for (int TestCase = 1; TestCase <= TotalTestCase; ++TestCase)
	{
		string First, Second;
		InputFile >> First >> Second;

		string RepeatFirst, RepeatSecond;
		for (int i = 0; i < Second.size(); i++)
		{
			RepeatFirst += First;
		}
		for (int i = 0; i < First.size(); i++)
		{
			RepeatSecond += Second;
		}

		if (RepeatFirst == RepeatSecond)
			cout << "#" << TestCase << " " << "yes" << endl;
		else
			cout << "#" << TestCase << " " << "no" << endl;

	}

	return 0;
}