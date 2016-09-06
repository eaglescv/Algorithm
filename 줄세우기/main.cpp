#include <stdio.h>
#include <vector>
#include <queue>
#pragma warning(disable:4996)

//¹®Á¦: [https://www.acmicpc.net/problem/2252]

using namespace std;
vector<int> S[32001];
int ind[32001];

int main()
{
	int N = 0;
	int M = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int A = 0;
		int B = 0;
		scanf("%d %d", &A, &B);
		S[A].push_back(B);
		ind[B] += 1;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++)
	{
		if (ind[i] == 0)
		{
			q.push(i);
		}
	}

	for (int k = 0; k < N; k++)
	{
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < (int)S[x].size(); i++)
		{
			int y = S[x][i];
			ind[y] -= 1;
			if (ind[y] == 0)
			{
				q.push(y);
			}
		}
	}
	printf("\n");
	return 0;
}