#include "pch.h"

int main()
{
	int testCase;
	int T;
	cin >> T;

	for (testCase = 1; testCase <= T; ++testCase)
	{
		int num1;
		int num2;
		cin >> num1;
		cin >> num2;

		const char* result{};
		if (num1 > num2)
			result = ">";
		else if (num1 < num2)
			result = "<";
		else
			result = "=";

		cout << "#" << testCase << " " << result << endl;
	}



	return 0;
}