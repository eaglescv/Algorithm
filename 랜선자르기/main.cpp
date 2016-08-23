#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int K = 0;
int N = 0;	//필요한 랜선 개수
vector<int> vLength;

int go(int X)
{
	int sum = 0;
	int size = (int)vLength.size();
	for (int i = 0; i < size; i++)
	{
		sum += vLength[i] / X;
	}

	if (sum < N)
	{
		return -1;
	}
	else if (sum > N)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int X = 10;
	int left = 0;
	int right = X;

	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++)
	{
		int length = 0;
		scanf("%d", &length);
		vLength.push_back(length);
	}

	while (1)
	{
		int result = go(X);
		if (result == 0)
		{
			break;
		}
		
		if (-1 == result)
		{
			left = (left + right) / 2;
			right = X -1;
			X = left;
		}
		else
		{
			right += (left + right) / 2;
			left = X + 1;
			X = right;
		}
	}
	
	printf("%d", X);
	return 0;
}