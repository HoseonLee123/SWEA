#include "pch.h"

bool compare(pair<int, double>& a, pair<int, double>& b)
{
	return a.second > b.second;
}

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1983_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int numberOfStudents; // multiple of 10, 10 ~ 100
		inputFile >> numberOfStudents;

		int curiousStudent; // 1 ~ numberOfStudents
		inputFile >> curiousStudent;

		// Score
		vector<pair<int, double>> totalScores;
		for (int i = 0; i < numberOfStudents; i++)
		{
			int mediumScore, finalScore, homeworkScore = 0;

			inputFile >> mediumScore >> finalScore >> homeworkScore;

			double score = mediumScore * 0.35 + finalScore * 0.45 + homeworkScore * 0.2;
			totalScores.push_back({ i, score });
		}

		// Credit
		int curiousStudentRank = 0;
		vector<string> credit = { "A+", "A0", "A-", "B+", "B0", "B-","C+","C0", "C-", "D0" };

		sort(totalScores.begin(), totalScores.end(), compare);

		for (int i = 0; i < numberOfStudents; i++)
		{
			if (totalScores[i].first == (curiousStudent - 1))
				break;

			++curiousStudentRank;
		}

		cout << "#" << testCase << " " << credit[curiousStudentRank / (numberOfStudents / 10)] << endl;
	}




	return 0;
}