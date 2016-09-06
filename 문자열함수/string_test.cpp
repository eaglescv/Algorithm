#include <stdio.h>
#include <string.h>

//strcmp함수 구현
int mystrcmp(const char* s1, const char* s2)
{
	int i = 0;
	int j = 0;
	while (s1[i] != '\0')
	{
		if (s1[i++] != s2[j++])
			break;
	}
	return (s1[i] - s2[j]);
}

//strcpy함수 구현
char* mystrcpy(char* s1, const char* s2)
{
	int i = 0;
	int j = 0;
	char* copy = s1;
	while (s2[i] != '\0')
		copy[j++] = s2[i++];
	copy[j] = '\0';

	return copy;
}

//strtok함수 구현
char* mystrtok(char* s1, char* s2)
{
	int i = 0;
	int temp = 0;
	int size = strlen(s1) - 1;//\n을 빼주기 위해
	
	for (i = 0; i < size; i++)
	{
		if (s1[i] == *s2)
		{
			s1[i] = '\0';
			printf("%s\n", &s1[temp]);
			temp = i + 1;
		}

		if (i == size - 1)
		{
			printf("%s\n", &s1[temp]);
		}
	}
	return 0;
}

//NC 기술면접2차.
//문자열의 앞뒤 공백은 빼고, 중간에 위치한 공백은 하기.
//버퍼를 쓰지 말기
char* mystrtok2(char* s1)
{
	return 0;
}

int main()
{
	return 0;
}