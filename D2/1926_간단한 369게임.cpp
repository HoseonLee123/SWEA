#include "pch.h"


int main()
{
	ifstream inputFile;
	inputFile.open("./input/1926_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int number;
	inputFile >> number;

	for (int i = 1; i <= number; i++)
	{
		string target = to_string(i);
		int numberOfHyphen{0};
		for (int j = 0; j < target.size(); j++)
		{
			if (target[j] == '3' || target[j] == '6' || target[j] == '9')
				++numberOfHyphen;
		}

		if (numberOfHyphen == 0)
		{
			cout << i << " ";
		}
		else
		{
			for (int i = 1; i <= numberOfHyphen; i++)
			{
				cout << "-";
			}
			cout << " ";
		}
	}

	return 0;
}