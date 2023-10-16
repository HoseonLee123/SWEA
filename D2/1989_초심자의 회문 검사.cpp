#include "pch.h"


int main()
{
	ifstream inputFile;
	inputFile.open("./input/1989_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		string input;
		inputFile >> input;

		bool isPalindrome{ true };
		for (int i = 0; i < (input.size() / 2); i++)
		{
			if (input[i] != input[input.size() - 1 - i])
			{
				isPalindrome = false;
				break;
			}
		}
		
		cout << "#" << testCase << " " << isPalindrome << endl;
	}




	return 0;
}