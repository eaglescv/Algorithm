#include <stdio.h>
#include <string.h>

//strcmp�Լ� ����
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

//strcpy�Լ� ����
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

//strtok�Լ� ����
char* mystrtok(char* s1, char* s2)
{
	int i = 0;
	int temp = 0;
	int size = strlen(s1) - 1;//\n�� ���ֱ� ����
	
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

//NC �������2��.
//���ڿ��� �յ� ������ ����, �߰��� ��ġ�� ������ �ϱ�.
//���۸� ���� ����
char* mystrtok2(char* s1)
{
	return 0;
}

int main()
{
	return 0;
}