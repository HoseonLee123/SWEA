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
		double curiousStudentScore = totalScores[curiousStudent - 1];

		// Where is the curious student?
		vector<double> descendingTotalScores = totalScores;
		sort(descendingTotalScores.begin(), descendingTotalScores.end(), greater<>{});

		int curiousIndex = 0;
		for (int i = 0; i < descendingTotalScores.size(); i++)
		{
			if (curiousStudentScore == descendingTotalScores[i])
			{
				curiousIndex = i;
				break;
			}
		}

		// Credit
		int numberOfSameCredit = descendingTotalScores.size() / 10;
		int temporaryCredit = 10; // 10 -> 1, A -> D0
		for (int i = 0; i < descendingTotalScores.size(); i = i + numberOfSameCredit)
		{
			int startIndex = i;
			for (int j = 0; j < numberOfSameCredit; j++)
			{
				descendingTotalScores[startIndex] = temporaryCredit;
				++startIndex;
			}

			--temporaryCredit;
		}

		int curiousCredit = descendingTotalScores[curiousIndex];
		string realCredit;
		switch (curiousCredit)
		{
		case 10:
			realCredit = "A+";
			break;
		case 9:
			realCredit = "A0";
			break;
		case 8:
			realCredit = "A-";
			break;
		case 7:
			realCredit = "B+";
			break;
		case 6:
			realCredit = "B0";
			break;
		case 5:
			realCredit = "B-";
			break;
		case 4:
			realCredit = "C+";
			break;
		case 3:
			realCredit = "C0";
			break;
		case 2:
			realCredit = "C-";
			break;
		case 1:
			realCredit = "D0";
			break;
		default:
			cout << "Credit Error!" << endl;
			break;
		}

		cout << "#" << testCase << " " << realCredit << endl;
	}




	return 0;
}