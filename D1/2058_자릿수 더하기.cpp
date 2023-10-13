#include "pch.h"


int main()
{
	ifstream inputFile;
	inputFile.open("./input/2058_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;
	
	int n;
	inputFile >> n;

	string target = to_string(n);
	int sum = 0;
	for (int i = 0; i < target.size(); i++)
	{
		sum += (target[i] - '0');
	}
	
	cout << sum << endl;

	return 0;
}