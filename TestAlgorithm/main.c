#include <stdio.h>
#include <string.h>

enum EWEEK
{
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

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

int IsLeapYears(int years)
{
	if ((years % 4 == 0 && years % 100 != 0) || years % 400 == 0)
	{
		return 1;
	}
	return 0;
}

int GetDayOfTheWeek(int years, int month, int day)
{
	int result = 0;

	switch (result)
	{
	default:
		break;
	}
	return result;
}

void main(int argc, char** args)
{
	//int gaussTotal = GaussAlgorithm();
	//printf("%d\n", gaussTotal);

	//int result = IsPalindrome(args[1]);
	//if (result)
	//{
	//	printf("it is palindrome\n");
	//}
	//else
	//{
	//	printf("it is NOT palindrome\n");
	//}

	//DoomsDay doomsday;

	getchar();
}