#include "pch.h"


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
		vector<double> totalScores(numberOfStudents, 0);
		for (int i = 0; i < numberOfStudents; i++)
		{
			int mediumScore, finalScore, homeworkScore = 0;

			inputFile >> mediumScore >> finalScore >> homeworkScore;

			double score = mediumScore * 0.35 + finalScore * 0.45 + homeworkScore * 0.2;
			totalScores[i] = score;
		}

		// Credit
		int curiousStudentRank = 0;
		vector<string> credit = { "A+", "A0", "A-", "B+", "B0", "B-","C+","C0", "C-", "D0" };
		
		for (int i = 0; i < numberOfStudents; i++)
		{
			if (totalScores[curiousStudent - 1] < totalScores[i])
				++curiousStudentRank;
		}

		cout << "#" << testCase << " " << credit[curiousStudentRank / (numberOfStudents / 10)] << endl;

		totalScores.clear();
	}




	return 0;
}