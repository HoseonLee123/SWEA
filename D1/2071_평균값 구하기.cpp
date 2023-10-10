#include "pch.h"

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int numbers[10]{};
		for (int i = 0; i < 10; i++)
		{
			cin >> numbers[i];
		}

		int sum{};
		for (int i = 0; i < 10; i++)
		{
			sum += numbers[i];
		}

		int average{};
		// Rounding out to the first decimal place.
		if (sum % 10 >= 5)
			average = sum / 10 + 1;
		else
			average = sum / 10;

		cout << "#" << test_case << " " << average << endl;
	}
	return 0;
}