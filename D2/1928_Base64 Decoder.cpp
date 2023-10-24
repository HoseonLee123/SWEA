#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1928_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		string encodedString;
		inputFile >> encodedString;

		string code = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

		string decodedString;
		for (int startIndex = 0; startIndex < encodedString.size(); startIndex = startIndex + 4)
		{
			int bit24 = 0;
			for (int repIndex = startIndex; repIndex < startIndex + 4; repIndex++)
			{
				int bit6 = code.find(encodedString[repIndex]);
				bit24 += bit6;
				bit24 <<= 6;
			}
			bit24 >>= 6;

			int extractFirstLetter = 0xFF0000;
			int extractSecondLetter = 0xFF00;
			int extractThirdLetter = 0xFF;

			char firstLetter = (bit24 & extractFirstLetter) >> 16;
			char secondLetter = (bit24 & extractSecondLetter) >> 8;
			char thirdLetter = bit24 & extractThirdLetter;

			decodedString.push_back(firstLetter);
			decodedString.push_back(secondLetter);
			decodedString.push_back(thirdLetter);
		}

		cout << "#" << testCase << " " << decodedString << endl;
	}


	return 0;
}