#include <stdio.h>

// �ִ� �����
int GCD(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

// �ּ� �����
int LCM(int a, int b)
{
	int g = GCD(a, b);
	return a * b / g;
}

int main()
{
	int result = GCD(1679, 874);
	printf("%d ", result);

	result = LCM(30, 36);
	printf("%d", result);
	return 0;
}