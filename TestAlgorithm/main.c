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

	getchar();
}

// �޷°� ����
#include <stdio.h>
void calendar(int year, int mon);    //������� ���ϰ�� 
void calendar_p();                      //�޷� ����Լ�
int i, j;
int day, mon, year;
int remain;
char week[7][3] = { "��", "��", "ȭ", "��", "��", "��", "��" };
int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
void main(){
	int num;
	char restart;
	do
	{
		printf("1.�޷�  2.����\n");
		printf("��ȣ : ");
		scanf_s("%d", &num);
		if (num == 1){
			printf("���� �Է� : ");
			scanf_s("%d", &year);
			printf("�� �Է� : ");
			scanf_s("%d", &mon);

			calendar(year, mon);
			calendar_p();
		}
		else if (num == 2){
			printf("���� �Է� : ");
			scanf_s("%d", &year);
			printf("�� �Է� : ");
			scanf_s("%d", &mon);
			printf("�� �Է� : ");
			scanf_s("%d", &day);
			calendar(year, mon);
			printf("\n   %d���� %s�����Դϴ�.\n", day, week[i]);
		}
		fflush(stdin);
		printf("�ٽ� �Է� �Ͻðڽ��ϱ� (Y/N) : ");
		scanf_s("%c", &restart);
	} while (restart == 'Y' || restart == 'y');
}
/*

��ó: http://wgkang80.tistory.com/156

<������ ��� ���>

1. �⺻������ 4�� ����� �Ǵ� �ش� ����.
2. �ٸ� 100�� ����� �Ǵ� �ش� ������ �ƴϴ�.
3. ���߿��� �� 400�� ����� �Ǵ� �ش� ����.


<���� ���ϴ� ���>

1����� ���ϰ��� �ϴ� �� 1�ϱ��� ��� �ϼ��� ���Ѵ�.
���� ��� 2007�� 3�� �޷��� ���ϰ��� �Ҷ�
1�� ���� 2007�� 3�� 1�� ���� ��� ������ ���Ѵ�.

��� �ϼ��� 7�� ������ ��������
0 �̸� �Ͽ���
1 �̸� ������
2 �̸� ȭ����
3 �̸� ������
....

*/

void calendar(int year, int mon){
	int allday;
	//���� ���� �״��� 1���� ���ϰ��

	allday = ((year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400);

	for (i = 0; i<mon; i++){
		if (i == 1 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)){
			month[1] += 1;
		}
		allday += month[i];
	}
	allday -= month[i - 1];
	remain = (allday + 1) % 7;
	i = (remain + day - 1) % 7; //���ϰ��
}

void calendar_p(){
	int count = 1;
	printf("\n\n  %d�� %d��\n", year, mon);
	printf("  ��  ��  ȭ  ��  ��  ��  ��\n");
	for (i = 0; i<6; i++){
		for (j = 0; j<7; j++){
			if (i == 0 && j<remain){
				printf("    ");
				continue;
			}
			else if (count >= month[mon - 1] + 1){
				break;
			}
			printf("%4d", count);
			count++;
		}
		printf("\n");
	}
}