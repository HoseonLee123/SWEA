#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1948_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		vector<int> month = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		int firstMonth, firstDay, secondMonth, secondDay;
		inputFile >> firstMonth >> firstDay >> secondMonth >> secondDay;

		int monthDiff = 0;
		for (; firstMonth < secondMonth; ++firstMonth)
		{
			monthDiff += month[firstMonth - 1];
		}

		int dayDiff = secondDay - firstDay + 1;

		cout << "#" << testCase << " " << (monthDiff + dayDiff) << endl;
	}

	return 0;
}