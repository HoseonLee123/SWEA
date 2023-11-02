#include "pch.h"

int main()
{
	ifstream InputFile;
	InputFile.open("./input/14692_input.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;

	for (int TestCase = 1; TestCase <= TotalTestCase; ++TestCase)
	{
		long long LogLength;
		InputFile >> LogLength;

		string winner;
		LogLength % 2 == 0 ? winner = "Alice" : winner = "Bob";

		cout << "#" << TestCase << " " << winner << endl;
	}

	return 0;
}