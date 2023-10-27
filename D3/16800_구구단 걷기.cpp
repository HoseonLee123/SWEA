#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/16800_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		long long target;
		inputFile >> target;

		// Prime factorization
		long long breakFlag = static_cast<long long>(sqrt(target));
		vector<pair<long long, long long>> factors;
		for (long long i = 1; i <= breakFlag; i++)
		{
			if (target % i == 0)
				factors.push_back({ i,(target / i) });
		}

		// Current location 1,1 
		vector<long long> movingCount;
		for (long long i = 0; i < factors.size(); i++)
		{
			movingCount.push_back((factors[i].first - 1) + (factors[i].second - 1));
		}
	
		cout << "#" << testCase << " " << *min_element(movingCount.begin(), movingCount.end()) << endl;

	}

	return 0;
}