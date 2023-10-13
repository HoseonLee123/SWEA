#include "pch.h"


int main()
{
	ifstream inputFile;
	inputFile.open("./input/1859_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int testCase;
	int T;
	inputFile >> T;

	for (testCase = 1; testCase <= T; ++testCase)
	{
		int N;
		inputFile >> N;

		vector<int> prices(N, 0);
		for (int i = 0; i < N; i++)
		{
			inputFile >> prices[i];
		}

		// Search from back!
		long long profit = 0;
		int maxPrice = 0;
		for (int i = (prices.size() - 1); i > -1; --i)
		{
			if (maxPrice < prices[i])
				maxPrice = prices[i];
			else
				profit += maxPrice - prices[i];
		}
		cout << "#" << testCase << " " << profit << endl;

		// Search from front!
		//long long profit = 0;
		//int startIndex = 0;
		//while (startIndex < N)
		//{
		//	// Find the maxPriceIndex.
		//	int maxPriceIndex = startIndex;
		//	for (int i = startIndex + 1; i < N; i++)
		//	{
		//		if (prices[maxPriceIndex] < prices[i])
		//			maxPriceIndex = i;
		//	}

		//	// Calculate the profit.
		//	for (int i = startIndex; i < maxPriceIndex; i++)
		//	{
		//		profit += prices[maxPriceIndex] - prices[i];
		//	}

		//	startIndex = maxPriceIndex + 1;
		//}
		//cout << "#" << testCase << " " << profit << endl;
	}

	return 0;
}