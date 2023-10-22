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

		vector<int> primeFactors = { 2,3,5,7,11 };
		int size = primeFactors.size();
		vector<int> numberOfPrimeFactors(size, 0);
		while (num > 1)
		{
			if (num % primeFactors[0] == 0)
			{
				++numberOfPrimeFactors[0];
				num /= primeFactors[0];
			}
			else if (num % primeFactors[1] == 0)
			{
				++numberOfPrimeFactors[1];
				num /= primeFactors[1];
			}
			else if (num % primeFactors[2] == 0)
			{
				++numberOfPrimeFactors[2];
				num /= primeFactors[2];
			}
			else if (num % primeFactors[3] == 0)
			{
				++numberOfPrimeFactors[3];
				num /= primeFactors[3];
			}
			else if (num % primeFactors[4] == 0)
			{
				++numberOfPrimeFactors[4];
				num /= primeFactors[4];
			}
			else
			{
				cout << "Found a prime factor other than 2, 3, 5, 7, 11." << endl;
				return -1;
			}
		}

		cout << "#" << testCase << " ";
		for (int i = 0; i < numberOfPrimeFactors.size(); i++)
		{
			cout << numberOfPrimeFactors[i] << " ";
		}
		cout << endl;
	}


	return 0;
}