#include <stdio.h>
#pragma warning(disable:4996)

/************************************************************************/
/*                                                                      
문제
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.
1.X가 3으로 나누어 떨어지면, 3으로 나눈다.
2.X가 2로 나누어 떨어지면, 2로 나눈다.
3.1을 뺀다.

입력
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최소값을 출력한다.

ex)
입력		출력
2		1
10		3
*/
/************************************************************************/
int d[1000001] = { 0, };

//Top-down
//go(10)
//d[0] = 0
//d[1] = 0
//d[2] = 1
//d[3] = 1
//d[4] = 2
//d[5] = 3
//d[6] = 2
//d[7] = 3
//d[8] = 3
//d[9] = 2
//d[10]= 3

//n == 9는 나누기 3으로 최소 연산 횟수는 2임. 
//9 / 3 = 3
//3 / 3 = 1

//n == 10은 연산 1회(n-1) + d[9]의 값 = 3임.
//문제의 조건은 3가지이지만, 숨은 조건이 하나 더 있음.
//연속된 수를 가정하므로 n = (n - 1)의 연산값 + 1

int go(int n)
{
	if (n == 1) return 0;		//Base Value
	if (d[n] > 0) return d[n];	//Memoization
	d[n] = go(n - 1) + 1;		//N => N -1
	if (n % 2 == 0)				//N => N / 2
	{
		int temp = go(n / 2) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	if (n % 3 == 0)				//N => N /3
	{
		int temp = go(n / 3) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	return d[n];
}

//Bottom-up
int go2(int n)
{
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;
		}
	}
	return d[n];
}

int main()
{
	int n;
	scanf("%d", &n);

	if (n < 1)
	{
		return 0;
	}

	int result = go(n);
	printf("%d", result);
	
	//printf("\n");
	//for (int i = 0; i <= n; i++)
	//{
	//	printf("%d ", d[i]);
	//}
	//printf("\n");
	return 0;
}
