#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1288_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int startSheep;
		inputFile >> startSheep;

		vector<int> rememberDigits(10, 0); // 0 ~ 9
		int breakSign = 0; // until 10
		string increasingSheep;

		for (int i = 1;; i++)
		{
			bool exitInfiniteLoop = false;
			increasingSheep = to_string(startSheep * i);

			for (int j = 0; j < increasingSheep.size(); j++)
			{
				int target = increasingSheep[j] - '0';
				if (rememberDigits[target] == 0)
				{
					++rememberDigits[target];
					++breakSign;
				}

				if (breakSign == 10)
				{
					exitInfiniteLoop = true;
					break;
				}
			}

			if (exitInfiniteLoop)
				break;
		}

		cout << "#" << testCase << " " << increasingSheep << endl;
	}


	return 0;
}