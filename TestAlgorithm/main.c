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

// 달력과 요일
#include <stdio.h>
void calendar(int year, int mon);    //윤년계산과 요일계산 
void calendar_p();                      //달력 출력함수
int i, j;
int day, mon, year;
int remain;
char week[7][3] = { "일", "월", "화", "수", "목", "금", "토" };
int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
void main(){
	int num;
	char restart;
	do
	{
		printf("1.달력  2.요일\n");
		printf("번호 : ");
		scanf_s("%d", &num);
		if (num == 1){
			printf("연도 입력 : ");
			scanf_s("%d", &year);
			printf("달 입력 : ");
			scanf_s("%d", &mon);

			calendar(year, mon);
			calendar_p();
		}
		else if (num == 2){
			printf("연도 입력 : ");
			scanf_s("%d", &year);
			printf("달 입력 : ");
			scanf_s("%d", &mon);
			printf("일 입력 : ");
			scanf_s("%d", &day);
			calendar(year, mon);
			printf("\n   %d일은 %s요일입니다.\n", day, week[i]);
		}
		fflush(stdin);
		printf("다시 입력 하시겠습니까 (Y/N) : ");
		scanf_s("%c", &restart);
	} while (restart == 'Y' || restart == 'y');
}
/*

출처: http://wgkang80.tistory.com/156

<윤년을 계산 방법>

1. 기본적으로 4의 배수가 되는 해는 윤년.
2. 다만 100의 배수가 되는 해는 윤년이 아니다.
3. 그중에서 또 400의 배수가 되는 해는 윤년.


<요일 구하는 방법>

1년부터 구하고자 하는 달 1일까지 모든 일수를 구한다.
예를 들면 2007년 3월 달력을 구하고자 할때
1년 부터 2007년 3월 1일 까지 모든 날수를 구한다.

모든 일수를 7로 나눠서 나머지가
0 이면 일요일
1 이면 월요일
2 이면 화요일
3 이면 수요일
....

*/

void calendar(int year, int mon){
	int allday;
	//윤년 계산과 그달의 1일의 요일계산

	allday = ((year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400);

	for (i = 0; i<mon; i++){
		if (i == 1 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)){
			month[1] += 1;
		}
		allday += month[i];
	}
	allday -= month[i - 1];
	remain = (allday + 1) % 7;
	i = (remain + day - 1) % 7; //요일계산
}

void calendar_p(){
	int count = 1;
	printf("\n\n  %d년 %d월\n", year, mon);
	printf("  일  월  화  수  목  금  토\n");
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