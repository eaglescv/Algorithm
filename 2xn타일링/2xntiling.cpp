#include <stdio.h>

int d[1001];

int sum(int n)
{
	if (n == 0) return 1;
	if (n == 1)	return 1;
	if (d[n] > 0) return d[n];

	int temp = sum(n - 1) + sum(n - 2);
	d[n] = temp % 10007;
	return d[n];
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int result = sum(n);
	printf("%d", result);
	return 0;
}

//#include <cstdio> 
//int d[1001];
//int main() {
//		d[0] = 1;
//		d[1] = 1;
//
//		int n;
//		scanf_s("%d", &n);
//		for (int i = 2; i <= n; i++) {
//				d[i] = d[i - 1] + d[i - 2];
//				d[i] %= 10007;
//		}
//		printf("%d\n", d[n]);
//		return 0;
//}
