// 1986
#include "pch.h"

int solution(int num)
{
	int sum = 0;

	for (int i = 1; i <= num; i++)
	{
		if (i % 2 == 1)
			sum += i;
		else
			sum -= i;
	}
	return sum;
}


int main()
{
	int n;
	cin >> n;
	cout << solution(n) << endl;
}