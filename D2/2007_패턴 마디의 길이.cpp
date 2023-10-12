#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/2007_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int testCase;
	int T;
	inputFile >> T;

	for (testCase = 1; testCase <= T; ++testCase)
	{
		string input;
		string target;

		inputFile >> input;
		target.push_back(input[0]);

		for (int i = 1; i < input.size(); i++)
		{
			if (target != input.substr(target.size(), i))
				target.push_back(input[i]);
			else
				break;
		}
		cout << "#" << testCase << " " << target.size() << endl;



		//string input;
		//cin >> input;
		//int length{};
		//bool isSame = true;;
		//for (int i = 2; i < input.size(); i++)
		//{
		//	if (input[0] == input[i])
		//	{
		//		for (int j = 1; j < i; j++)
		//		{
		//			if (input[0 + j] != input[i + j])
		//			{
		//				isSame = false;
		//				break;
		//			}
		//			isSame = true;
		//		}

		//		if (isSame)
		//		{
		//			length = i;
		//			break;
		//		}
		//	}
		//}

		//cout << "#" << testCase << " " << length << endl;
	}



	return 0;
}