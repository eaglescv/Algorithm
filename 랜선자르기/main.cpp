#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int K = 0;
int N = 0;	//필요한 랜선 개수
vector<int> vLength;

bool check(long long x)
{
	long long sum = 0;
	int size = (int)vLength.size();
	for (int i = 0; i < size; i++)
	{
		sum += vLength[i] / x;
	}
	
	return sum >= N;
}

int main()
{
	long long mid = 0;
	long long right = 0;
	long long left = 1;
	long long result = 0;

	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++)
	{
		int length = 0;
		scanf("%d", &length);
		vLength.push_back(length);
		if (right < length)
		{
			right = length;
		}
	}

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (check(mid))
		{
			if (result < mid)
			{
				result = mid;
			}
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	
	printf("%d", result);
	return 0;
}