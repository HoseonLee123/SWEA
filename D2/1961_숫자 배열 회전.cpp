#include "pch.h"

void Rotate(vector<vector<int>>& original, vector<vector<int>>& target)
{
	for (int i = 0; i < target.size(); i++)
	{
		for (int j = 0; j < target.size(); j++)
		{
			target[i][j] = original[target.size() -1 - j][i];
		}
	}
}

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1961_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int size;
		inputFile >> size;

		vector<vector<int>> matrix(size, vector<int>(size, 0));
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				inputFile >> matrix[i][j];
			}
		}

		vector<vector<int>> matrixRotated90(size, vector<int>(size, 0));
		Rotate(matrix, matrixRotated90);

		vector<vector<int>> matrixRotated180(size, vector<int>(size, 0));
		Rotate(matrixRotated90, matrixRotated180);

		vector<vector<int>> matrixRotated270(size, vector<int>(size, 0));
		Rotate(matrixRotated180, matrixRotated270);

		cout << "#" << testCase << endl;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << matrixRotated90[i][j];
			}
			cout << " ";

			for (int j = 0; j < size; j++)
			{
				cout << matrixRotated180[i][j];
			}
			cout << " ";

			for (int j = 0; j < size; j++)
			{
				cout << matrixRotated270[i][j];
			}
			
			cout << endl;
		}
	}




	return 0;
}