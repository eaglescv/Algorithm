#include <stdio.h>
#include <string.h>

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

int IsPalindrome(char* inputString)
{
	int index;
	int length = strlen(inputString);
	int testEndingIndex = length / 2;
	int preindex = length - 1;
	for (index = 0; index < testEndingIndex; index++)
	{
		if (inputString[index] != inputString[preindex - index])
		{
			return 0;
		}
	}
	return 1;
}

void main(int argc, char** args)
{
	//int gaussTotal = GaussAlgorithm();
	//printf("%d\n", gaussTotal);

	int result = IsPalindrome(args[1]);
	if (result)
	{
		printf("it is palindrome\n");
	}
	else
	{
		printf("it is NOT palindrome\n");
	}
	getchar();
}