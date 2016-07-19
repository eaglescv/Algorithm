#include "stdio.h"

int item[99] = { 0, };

int GaussAlgorithm()
{
	for (int i = 0; i <= 99; ++i)
	{
		item[i] = i + 1;
	}

	int gaussTotal = 5050;
	for (int i = 0; i < 99; i++)
	{
		gaussTotal = gaussTotal - item[i];
	}
	return gaussTotal;
}

void main()
{
	int gaussTotal = GaussAlgorithm();
	printf("%d\n", gaussTotal);
	getchar();
}