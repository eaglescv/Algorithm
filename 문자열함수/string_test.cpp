#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

//strlen함수 구현
int mystrlen(char* s1)
{
	int len = 0;
	while (s1[len++]);
	return len - 1;
}

//strcmp함수 구현
int mystrcmp(const char* s1, const char* s2)
{
	for (; *s1 == *s2; s1++, s2++);
	if (*s1 == '\0') return 0;

	if (*s1 > *s2) return 1;
	else return -1;
}

//strcpy함수 구현
char* mystrcpy(char* dest, const char* src)
{
	char* pTempDest = dest;
	const char* pTempSrc = src;
	int i = 0;
	while (*pTempSrc != NULL)
	{
		*pTempDest++ = *pTempSrc++; 
		i++;
	}
	dest[i] = '\0';
	return dest;
}

//strtok함수 구현
char* mystrtok(char* s1, const char* delim)
{
	static char* src;
	const char* del;

	if (s1 == NULL && strlen(src) > 0)
	{
		s1 = src;
	}
	else if (s1 != NULL)
	{
		src = s1;
	}
	else
	{
		return NULL;
	}

	int i = 0;
	while (*src)
	{
		del = delim;
		while (*del)
		{
			if (*src == *del)
			{
				src++;
				s1[i] = '\0';
				return s1;
			}
			del++;
		}
		src++;
		i++;
	}
	return s1;
}

//NC 기술면접2차.
//문자열의 앞뒤 공백은 빼고, 중간에 위치한 공백은 유지하기
//버퍼를 쓰지 말기
char* nc_strtok(char* s1)
{
	int len = strlen(s1);
	int i = 0;
	int j = 0;
	const char* src = s1;

	for (; i < len; i++)
	{
		if (src[i] == ' ' && (i == 0 || i == (len - 1)))
		{
			continue;
		}
		s1[j] = src[i];
		j++;
	}
	s1[j] = '\0';
	return s1;
}

//문자열 거꾸로 뒤집는 함수 만들기
char* ReversePrint(char* str)
{
	int length = strlen(str);

	int i = 0;
	char ss[100] = { 0, };
	for (; i < length; ++i)
	{
		ss[i] = str[length - (i + 1)];
	}
	ss[i] = '\0';
	strcpy(str, ss);
	return str;
}

int main()
{
	int len = mystrlen("aaeebdd");
	printf("strlen:%d\n", len);

	int a = mystrcmp("ABDDDE", "DBDDDE");
	printf("strcmp:%d\n", a);

	char TEST[1024] = { "abcd", };
	char* copy = mystrcpy(TEST, "A");
	printf("strcpy:%s\n", copy);

	char STRTOK_TEST[100] = "You are a girl.";
	char* token = mystrtok(STRTOK_TEST, " ");
	while (token != NULL)
	{
		printf("mystrtok:%s\n", token);
		token = mystrtok(NULL, " ");
	}

	char NC_SOFT_STR[100] = "I AM A BOY. ";
	char* result = nc_strtok(NC_SOFT_STR);
	printf("NC:%s\n", result);

	char reverse_test[100] = "I am a GameProgrammer.";
	char* reverse = ReversePrint(reverse_test);
	len = strlen(reverse);
	for (int i = 0; i < len; ++i)
	{
		printf("%c", reverse[i]);
	}

	return 0;
}