#include <stdio.h>
#pragma warning(disable:4996)

int d[1000001] = { 0, };

int go(int n)
{
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];
	d[n] = go(n - 1) + 1;	//N => N -1
	if (n % 2 == 0)			//N => N / 2
	{
		int temp = go(n / 2) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	if (n % 3 == 0)			//N => N /3
	{
		int temp = go(n / 3) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	return d[n];
}

int main()
{
	int n;
	scanf("%d", &n);
	//int result = go(n);
	int result = 0;
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i/2] + 1)
		{
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i/3] + 1)
		{
			d[i] = d[i / 3] + 1;
		}
	}
	printf("%d", d[n]);
	return 0;
}