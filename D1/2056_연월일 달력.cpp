#include "pch.h"


int main()
{
	ifstream inputFile;
	inputFile.open("./input/2056_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int input;
		inputFile >> input;

		bool validation = true;

		// Month validation
		int month = (input % 10000) / 100;
		if (!(month >= 1 && month <= 12))
			validation = false;

		// Day validation
		int day = (input % 10000) % 100;
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		{
			if (!(day >= 1 && day <= 31))
				validation = false;
		}
		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		{
			if (!(day >= 1 && day <= 30))
				validation = false;
		}
		else if(month == 2)
		{
			if (!(day >= 1 && day <= 28))
				validation = false;
		}

		// Print
		if (validation)
		{
			string stringifiedInput = to_string(input);
			string format;

			if (stringifiedInput.size() < 8)
			{
				for (int i = 0; i < 8 - stringifiedInput.size(); i++)
				{
					format.push_back('0');
				}
			}

			for (int i = 0; i < stringifiedInput.size(); i++)
			{

				format.push_back(stringifiedInput[i]);

				if(format.size() == 4 || format.size() == 7)
					format.push_back('/');
			}

			cout << "#" << testCase << " " << format << endl;

		}
		else
		{
			cout << "#" << testCase << " " << "-1" << endl;
		}
	}

	return 0;
}