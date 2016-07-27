#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)

#ifdef WIN32
#define MAX_BOARDSIZE 21
typedef unsigned __int64 SOLUTIONTYPE;
#else
#define MAX_BOARDSIZE 18
typedef unsigned long SOLUTIONTYPE;
#endif	//WIN32

#define MIN_BOARDSIZE 2
SOLUTIONTYPE g_numsolutions = 0;

//해에 따라서 체스판 위에 배열된 여왕들을 출력한다.
void printtable(int boardsize, int* aQueenBitRes, SOLUTIONTYPE numSolution)
{
	int i, j, k, row;

	for (k = 0; k < 2; ++k)
	{
#ifdef WIN32
		printf("*** Solution #: %I64d ***\n", 2 * numSolution + k - 1);
#else
		printf("*** Solution #: %d ***\n", 2 * numSolution + k - 1);
#endif	//WIN32

		for (i = 0; i < boardsize; i++)
		{
			unsigned int bitf;

			//1로 설정된 열을 찾는다.(즉 1로 설정되어 있는 값 중에서 제일 오른쪽에 있는 값을 찾는다)
			//만약 aQueenBitRes[i]가 011010b였다면, bitf = 000010b가 된다.
			bitf = aQueenBitRes[i];
			row = bitf ^ (bitf & (bitf - 1));
			
			//최하위 비트 값을 구한다.
			for (j = 0; j < boardsize; j++)
			{
				//이진수 표현에서 '1'을 찾을 때까지 계속 오른쪽으로 이동한다.
				//'1'은 오직 하나만 존재할 것이다.
				if (0 == k && ((row >> j) &1))
				{
					printf("Q");
				}
				//Y축을 따라서 반사된 체스판을 구하는 과정이다.
				else if (1 == k && (row & (1 << (boardsize - j - 1))))
				{
					printf("Q");
				}
				else
				{
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}

void Nqueen(int board_size)
{
	int aQueenBitRes[MAX_BOARDSIZE];
	int aQueenBitCol[MAX_BOARDSIZE];

	//이미 여왕이 있는 대각선 위치를 표시한다.
	int aQueenBitPosDiag[MAX_BOARDSIZE];
	int aQueenBitNegDiag[MAX_BOARDSIZE];

	//재귀 알고리즘 대신 스택을 이용한다.
	int aStack[MAX_BOARDSIZE + 2];
	register int* pnStack;

	//중복된 numrows: 스택을 이용할 수 있다.
	register int numrows = 0;

	//최하위 비트: 맨 오른쪽 비트
	register unsigned int lsb;

	//1로 설정된 비트들은 여왕을 놓을 수 있는 자리를 의미한다.
	register unsigned int bitfield;
	int i;

	//체스판의 크기(열과 행의 갯수)가 짝수면 0, 홀수면 1
	int odd = board_size & 1;

	//체스판 크기 - 1
	int board_minus = board_size - 1;

	//만약 체스판의 크기가 N이면 mask는 N개의 1로 이루어진다.
	int mask = (1 << board_size) - 1;

	//스택을 초기화한다.
	//경계를 설정 : 스택의 끝을 의미한다.
	aStack[0] = -1;

	//board_size가 홀수면 (board_size & 1)은 반드시 참이다.
	//만약 board_size가 홀수면 루프를 한 번 더 돌려야 한다.
	for (i = 0; i < (1 + odd); ++i)
	{
		bitfield = 0;
		if (0 == i)
		{
			//가운데 열을 제외한 체스판의 절반만 다룬다. 따라서 만약 체스판의 크기가 5X5라면 첫 번째 행은 00011이 될 것이다.
			//여왕을 가운데 열에 놓는 경우는 (아직) 고려하지 않는다.

			//2로 나눈다.
			int half = board_size >> 1;

			//행의 오른쪽 절반을 1로 채운다. 만약 행의 크기가 7이라면 그 절반은 (나머지를 무시하면) 3이다.
			//이 경우 bitfield의 값은 이진수로 111이 될 것이다.
			bitfield = (1 << half) - 1;
			
			//스택 포인터
			pnStack = aStack + 1;

			aQueenBitRes[0] = 0;
			aQueenBitCol[0] = aQueenBitPosDiag[0] = aQueenBitNegDiag[0] = 0;
		}
		else
		{
			//(홀수 크기를 갖는 체스판에서) 가운데 열을 계산한다.
			//우선 가운데 열의 비트를 1로 설정하고 다음 열의 절반에 대해서 값을 설정한다.
			//따라서 첫 번째 행(하나의 요소)과 다음 행의 절반을 처리하고 있는 것이다.
			//만약 체스판의 크기가 5X5라면, 첫 번째 행은 00100 그리고 다음 행은 00011이 될 것이다.
			bitfield = 1 << (board_size >> 1);
			numrows = 1;	//0일지도 모르므로

			//첫 번째 행은 (가운데 열에) 하나의 여왕을 가지고 있다.
			aQueenBitRes[0] = bitfield;
			aQueenBitCol[0] = aQueenBitPosDiag[0] = aQueenBitNegDiag[0] = 0;
			aQueenBitCol[1] = bitfield;

			//이제 다음 행을 처리한다. 나머지 반은 나중에 'Y축' 을 따라 반사시켜서 처리할 것이므로
			//여기에서는 절반에 대해서만 값을 정한다.
			aQueenBitNegDiag[1] = (bitfield >> 1);
			aQueenBitPosDiag[1] = (bitfield << 1);
			pnStack = aStack + 1;

			//이 행에는 하나의 요소만 존재하므로 이 행의 처리가 끝났다.
			*pnStack++ = 0;

			//bitfield - 1은 하나의 1 왼쪽으로는 모두 1이다.
			bitfield = (bitfield - 1) >> 1;
		}

		for (;;)
		{
			lsb = bitfield ^ (bitfield & (bitfield - 1));

			//이 계산은 2의 보수(2`s complement)아키텍쳐를 가정한다.
			lsb = -((signed)bitfield) & bitfield;

			if (0 == bitfield)
			{
				//스택으로부터 앞의 값을 구한다.
				bitfield = *--pnStack;
				if (pnStack == aStack)
				{
					//만약 스택의 끝이라면...
					break;
				}
				--numrows;
				continue;
			}

			//이 비트의 값을 바꿔서 나중에 다시 계산하지 않도록 한다.
			bitfield &= ~lsb;

			//결과를 저장한다.
			aQueenBitRes[numrows] = lsb;

			//처리할 행이 아직 남아 있는가?
			if (numrows < board_minus)
			{
				int n = numrows++;
				aQueenBitCol[numrows] = aQueenBitCol[n] | lsb;
				aQueenBitNegDiag[numrows] = (aQueenBitNegDiag[n] | lsb) >> 1;
				aQueenBitPosDiag[numrows] = (aQueenBitNegDiag[n] | lsb) << 1;
				*pnStack++ = bitfield;

				//다른 여왕이 이미 차지한 행, 열, 혹은 대각선에 다른 여왕을 놓을 수 없다.
				bitfield = mask & ~(aQueenBitCol[numrows] | aQueenBitNegDiag[numrows] | aQueenBitPosDiag[numrows]);
				continue;
			}
			else
			{ 
				//더 이상 처리할 행이 없다. 즉 해를 찾은 것이다.
				printtable(board_size, aQueenBitRes, g_numsolutions + 1);
				++g_numsolutions;
				bitfield = *--pnStack;
				--numrows;
				continue;
			}
		}
	}

	//반사된 이미지를 고려하기 위해서 해의 갯수에 2를 곱한다.
	g_numsolutions *= 2;
}

//실행이 끝난 후 결과를 출력한다.
void printResults(time_t* pt1, time_t* pt2)
{
	double secs;
	int hours, mins, intsecs;
	printf("End: \t%s", ctime(pt2));
	secs = difftime(*pt2, *pt1);
	intsecs = (int)secs;
	printf("Calculations took %d second%s.\n", intsecs, (intsecs == 1 ? " " : "s"));

	//시, 분, 초를 출력한다.
	hours = intsecs / 3600;
	intsecs -= hours * 3600;
	mins = intsecs / 60;
	intsecs -= mins * 60;
	if (hours > 0 || mins > 0)
	{
		printf("Equals ");
		if (hours > 0)
		{
			printf("%d hour%s, ", hours, (hours == 1) ? " " : "s");
		}
		if (mins > 0)
		{
			printf("%d minute%s and ", mins, (mins == 1) ? " " : "s");
		}
		printf("%d second%s.\n", intsecs, (intsecs == 1 ? " " : "s"));
	}
}

//N개의 여왕 프로그램의 메인 루틴
//명령 인수에 보드 사이즈를 넣어주면 됌.(ex: 4)
void main(int argc, char** argv)
{
	time_t t1, t2;
	int boardsize;

	if (argc != 2)
	{
		printf("N Queens program by Jeff Somers.\n");
		printf("This program calculates the total number of solutions to the N Queens problem.\n");
		printf("Usage: nq <width of board>\n");

		getchar();
		return;
	}

	boardsize = atoi(argv[1]);

	//체스판의 크기가 정확한 범위 내에 존재하는지 여부를 확인한다.
	if (MIN_BOARDSIZE > boardsize || MAX_BOARDSIZE < boardsize)
	{
		printf("Width of board must be between %d and %d, inclusive.\n", MIN_BOARDSIZE, MAX_BOARDSIZE);

		getchar();
		return;
	}

	time(&t1);
	printf("N Queens program by Jeff Somers.\n");
	printf("allagash98@yahoo.com or jsomers@alumni.williams.edu\n");
	printf("Start:\t %s", ctime(&t1));

	Nqueen(boardsize);
	time(&t2);

	printResults(&t1, &t2);

	if (g_numsolutions != 0)
	{
#ifdef WIN32
		printf("For board size %d, %I64d solution%s found.\n", boardsize, g_numsolutions, (g_numsolutions == 1 ? " " : "s"));
#else
		printf("For board size %d, %d solution%s found.\n", boardsize, g_numsolutions, (g_numsolutions == 1 ? " " : "s"));
#endif	//WIN32
	}
	else
	{
		printf("No solutions found.\n");
	}

	getchar();
}