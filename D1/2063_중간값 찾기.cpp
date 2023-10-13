#include "pch.h"


int main()
{
	ifstream inputFile;
	inputFile.open("./input/2063_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int N;
	inputFile >> N; // Always odd number, 9 <= N <= 199

	vector<int> scores(N, 0);
	for (int i = 0; i < N; ++i)
	{
		inputFile >> scores[i];
	}

	sort(scores.begin(), scores.end());

	int median = scores[(scores.size() - 1) / 2];
	cout << median << endl;

	return 0;
}