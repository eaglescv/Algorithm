#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

char* ReversePrint(char* str)
{
	int length = strlen(str);
	//for (int i = 0; i < length; ++i)
	//{
	//	printf("%c", str[i]);
	//}
	//printf("\n");
	
	int i = 0;
	char ss[100] = { 0, };
	for ( ; i < length; ++i)
	{
		ss[i] = str[length - (i + 1)];
	}
	ss[i] = '\0';
	strcpy(str, ss);
	return str;
}

void main()
{
	char a[100] = "I am a boy.";
	char* reverse = ReversePrint(a);
	int len = strlen(reverse);
	for (int i = 0; i < len; ++i)
	{
		printf("%c", reverse[i]);
	}
	getchar();
}