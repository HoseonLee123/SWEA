#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1970_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int change; // 10 ~  1,000,000
		inputFile >> change;

		vector<int> wons = { 50000,10000,5000,1000,500,100,50,10 };

		cout << "#" << testCase << endl;
		for (int i = 0; i < wons.size(); i++)
		{
			cout << change / wons[i] << " ";
			change %= wons[i];
		}
		cout << endl;
	}

	return 0;
}