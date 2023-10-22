#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1945_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		// num = 2^a * 3^b * 5^c * 7^d * 11^e
		int num;
		inputFile >> num; // 2~10,000,000

		vector<int> primeFactors(5, 0); // 2, 3, 5, 7, 11

		while (num > 1)
		{
			if (num % 2 == 0)
			{
				++primeFactors[0];
				num /= 2;
			}
			else if (num % 3 == 0)
			{
				++primeFactors[1];
				num /= 3;
			}
			else if (num % 5 == 0)
			{
				++primeFactors[2];
				num /= 5;
			}
			else if (num % 7 == 0)
			{
				++primeFactors[3];
				num /= 7;
			}
			else if (num % 11 == 0)
			{
				++primeFactors[4];
				num /= 11;
			}
			else
			{
				cout << "Found a prime factor other than 2, 3, 5, 7, 11." << endl;
				return -1;
			}
		}

		cout << "#" << testCase << " ";
		for (int i = 0; i < primeFactors.size(); i++)
		{
			cout << primeFactors[i] << " ";
		}
		cout << endl;
	}


	return 0;
}