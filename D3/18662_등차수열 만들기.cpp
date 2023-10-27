#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/18662_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		double a, b, c; // 0 ~ 1000
		inputFile >> a >> b >> c;

		double x{}; // > 0
		vector<double> possibleX;

		// a + x, b, c
		possibleX.push_back(abs(2 * b - a - c));

		// a, b + x, c
		possibleX.push_back(abs((a + c) / 2.0 - b));

		// a, b, c + x
		possibleX.push_back(abs(2 * b - a - c));

		sort(possibleX.begin(), possibleX.end());
		x = possibleX[0];

		cout << fixed;
		cout.precision(1);
		cout << "#" << testCase << " " << x << endl;
	}

	return 0;
}