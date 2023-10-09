#include "pch.h"


int main()
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<int> numbers;
		for (int i = 0; i < 10; i++)
		{
			int num;
			cin >> num;
			numbers.push_back(num);
		}

		int sum = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] % 2 == 1)
				sum += numbers[i];
		}

		cout << "#" << test_case << " " << sum << endl;
	}

	return 0;
}