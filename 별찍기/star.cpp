#include <iostream>
using namespace std;

//º°Âï±â - 1
//*
//**
//***
//****
//*****
//https://www.acmicpc.net/problem/2438
void PrintStar(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}

//º°Âï±â - 2
//https://www.acmicpc.net/problem/2439
void PrintStar2(int n)
{
	// n = 5 °ø¹é			º°
	//    * (n-1)	n - (n-1) => n - 4 => (5 - 4 = 1)
	//   ** (n-2)	n - (n-2) => n - 2 => (5 - 3 = 2)
	//  *** (n-3)	n - (i-3) => n - 3 => (5 - 2 = 3)
	// **** (n-4)	n - (i-4) => n - 4 => (5 - 1 = 4)
	//***** (n-5)	n - (i-5) -> n - 5 => (5 - 0 = 5)
	//for (int i = 1; i <= n; i++)
	//{
	//	int j = i;
	//	for (; j < n; j++)
	//	{
	//		printf(" ");
	//	}

	//	for (int k = n - i; k < n; k++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}

	for (int i = 1; i <= n; printf("\n", i++))
		for (int j = 1; j <= n; j++)
			printf("%c", i + j <= n ? ' ' : '*');
}

//º°Âï±â - 5
//https://www.acmicpc.net/problem/2442
void PrintStar5(int n)
{
	for (int i = 1; i <= n; printf("\n", i++))
	{
		for (int j = 1; j <= n; j++)
		{
			//2*n-1
			//2*5-1 => 9

		}
	}
}

int main()
{
	int n = 0;
	cin >> n;

	//PrintStar2(n);
	PrintStar5(n);
	return 0;
}