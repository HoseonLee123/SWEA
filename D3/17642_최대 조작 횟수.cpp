#include "pch.h"

int main()
{
	ifstream InputFile;
	InputFile.open("./input/17642_input.txt");

	if (!InputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int TotalTestCase;
	InputFile >> TotalTestCase;

	for (int TestCase = 1; TestCase <= TotalTestCase; ++TestCase)
	{
		// (A + prime number)-> <-(B - prime number)
		long long A, B;
		InputFile >> A >> B;

		long long Diff = B - A;

		if (Diff != 1 && Diff >= 0)
		{
			cout << "#" << TestCase << " " << Diff / 2 << endl;
		}
		else
		{
			cout << "#" << TestCase << " " << -1 << endl;
		}

	}

	return 0;
}