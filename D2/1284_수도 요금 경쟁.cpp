#include "pch.h"

int main()
{
	ifstream inputFile;
	inputFile.open("./input/1284_input.txt");

	if (!inputFile.is_open())
		cout << "Error! Failed to open the file!" << endl;

	int toalTestCase;
	inputFile >> toalTestCase;

	for (int testCase = 1; testCase <= toalTestCase; ++testCase)
	{
		int ACompanyWaterPrice; // 1~10000
		int BCompanyWaterPriceUnderBasicCharge;
		int BCompanyBasicChargeUsage;
		int BComanyWaterPriceOverBasicCharge;
		int usage;

		inputFile
			>> ACompanyWaterPrice
			>> BCompanyWaterPriceUnderBasicCharge
			>> BCompanyBasicChargeUsage
			>> BComanyWaterPriceOverBasicCharge
			>> usage;

		int ACompanyWaterCharge = ACompanyWaterPrice * usage;
		int BCompanyWaterCharge;
		if (usage <= BCompanyBasicChargeUsage)
		{
			BCompanyWaterCharge = BCompanyWaterPriceUnderBasicCharge;
		}
		else
		{
			BCompanyWaterCharge = BCompanyWaterPriceUnderBasicCharge + BComanyWaterPriceOverBasicCharge * (usage - BCompanyBasicChargeUsage);
		}

		int finalChoice = min(ACompanyWaterCharge, BCompanyWaterCharge);

		cout << "#" << testCase << " " << finalChoice << endl;

	}


	return 0;
}