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

//�ؿ� ���� ü���� ���� �迭�� ���յ��� ����Ѵ�.
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

			//1�� ������ ���� ã�´�.(�� 1�� �����Ǿ� �ִ� �� �߿��� ���� �����ʿ� �ִ� ���� ã�´�)
			//���� aQueenBitRes[i]�� 011010b���ٸ�, bitf = 000010b�� �ȴ�.
			bitf = aQueenBitRes[i];
			row = bitf ^ (bitf & (bitf - 1));
			
			//������ ��Ʈ ���� ���Ѵ�.
			for (j = 0; j < boardsize; j++)
			{
				//������ ǥ������ '1'�� ã�� ������ ��� ���������� �̵��Ѵ�.
				//'1'�� ���� �ϳ��� ������ ���̴�.
				if (0 == k && ((row >> j) &1))
				{
					printf("Q");
				}
				//Y���� ���� �ݻ�� ü������ ���ϴ� �����̴�.
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

	//�̹� ������ �ִ� �밢�� ��ġ�� ǥ���Ѵ�.
	int aQueenBitPosDiag[MAX_BOARDSIZE];
	int aQueenBitNegDiag[MAX_BOARDSIZE];

	//��� �˰��� ��� ������ �̿��Ѵ�.
	int aStack[MAX_BOARDSIZE + 2];
	register int* pnStack;

	//�ߺ��� numrows: ������ �̿��� �� �ִ�.
	register int numrows = 0;

	//������ ��Ʈ: �� ������ ��Ʈ
	register unsigned int lsb;

	//1�� ������ ��Ʈ���� ������ ���� �� �ִ� �ڸ��� �ǹ��Ѵ�.
	register unsigned int bitfield;
	int i;

	//ü������ ũ��(���� ���� ����)�� ¦���� 0, Ȧ���� 1
	int odd = board_size & 1;

	//ü���� ũ�� - 1
	int board_minus = board_size - 1;

	//���� ü������ ũ�Ⱑ N�̸� mask�� N���� 1�� �̷������.
	int mask = (1 << board_size) - 1;

	//������ �ʱ�ȭ�Ѵ�.
	//��踦 ���� : ������ ���� �ǹ��Ѵ�.
	aStack[0] = -1;

	//board_size�� Ȧ���� (board_size & 1)�� �ݵ�� ���̴�.
	//���� board_size�� Ȧ���� ������ �� �� �� ������ �Ѵ�.
	for (i = 0; i < (1 + odd); ++i)
	{
		bitfield = 0;
		if (0 == i)
		{
			//��� ���� ������ ü������ ���ݸ� �ٷ��. ���� ���� ü������ ũ�Ⱑ 5X5��� ù ��° ���� 00011�� �� ���̴�.
			//������ ��� ���� ���� ���� (����) ������� �ʴ´�.

			//2�� ������.
			int half = board_size >> 1;

			//���� ������ ������ 1�� ä���. ���� ���� ũ�Ⱑ 7�̶�� �� ������ (�������� �����ϸ�) 3�̴�.
			//�� ��� bitfield�� ���� �������� 111�� �� ���̴�.
			bitfield = (1 << half) - 1;
			
			//���� ������
			pnStack = aStack + 1;

			aQueenBitRes[0] = 0;
			aQueenBitCol[0] = aQueenBitPosDiag[0] = aQueenBitNegDiag[0] = 0;
		}
		else
		{
			//(Ȧ�� ũ�⸦ ���� ü���ǿ���) ��� ���� ����Ѵ�.
			//�켱 ��� ���� ��Ʈ�� 1�� �����ϰ� ���� ���� ���ݿ� ���ؼ� ���� �����Ѵ�.
			//���� ù ��° ��(�ϳ��� ���)�� ���� ���� ������ ó���ϰ� �ִ� ���̴�.
			//���� ü������ ũ�Ⱑ 5X5���, ù ��° ���� 00100 �׸��� ���� ���� 00011�� �� ���̴�.
			bitfield = 1 << (board_size >> 1);
			numrows = 1;	//0������ �𸣹Ƿ�

			//ù ��° ���� (��� ����) �ϳ��� ������ ������ �ִ�.
			aQueenBitRes[0] = bitfield;
			aQueenBitCol[0] = aQueenBitPosDiag[0] = aQueenBitNegDiag[0] = 0;
			aQueenBitCol[1] = bitfield;

			//���� ���� ���� ó���Ѵ�. ������ ���� ���߿� 'Y��' �� ���� �ݻ���Ѽ� ó���� ���̹Ƿ�
			//���⿡���� ���ݿ� ���ؼ��� ���� ���Ѵ�.
			aQueenBitNegDiag[1] = (bitfield >> 1);
			aQueenBitPosDiag[1] = (bitfield << 1);
			pnStack = aStack + 1;

			//�� �࿡�� �ϳ��� ��Ҹ� �����ϹǷ� �� ���� ó���� ������.
			*pnStack++ = 0;

			//bitfield - 1�� �ϳ��� 1 �������δ� ��� 1�̴�.
			bitfield = (bitfield - 1) >> 1;
		}

		for (;;)
		{
			lsb = bitfield ^ (bitfield & (bitfield - 1));

			//�� ����� 2�� ����(2`s complement)��Ű���ĸ� �����Ѵ�.
			lsb = -((signed)bitfield) & bitfield;

			if (0 == bitfield)
			{
				//�������κ��� ���� ���� ���Ѵ�.
				bitfield = *--pnStack;
				if (pnStack == aStack)
				{
					//���� ������ ���̶��...
					break;
				}
				--numrows;
				continue;
			}

			//�� ��Ʈ�� ���� �ٲ㼭 ���߿� �ٽ� ������� �ʵ��� �Ѵ�.
			bitfield &= ~lsb;

			//����� �����Ѵ�.
			aQueenBitRes[numrows] = lsb;

			//ó���� ���� ���� ���� �ִ°�?
			if (numrows < board_minus)
			{
				int n = numrows++;
				aQueenBitCol[numrows] = aQueenBitCol[n] | lsb;
				aQueenBitNegDiag[numrows] = (aQueenBitNegDiag[n] | lsb) >> 1;
				aQueenBitPosDiag[numrows] = (aQueenBitNegDiag[n] | lsb) << 1;
				*pnStack++ = bitfield;

				//�ٸ� ������ �̹� ������ ��, ��, Ȥ�� �밢���� �ٸ� ������ ���� �� ����.
				bitfield = mask & ~(aQueenBitCol[numrows] | aQueenBitNegDiag[numrows] | aQueenBitPosDiag[numrows]);
				continue;
			}
			else
			{ 
				//�� �̻� ó���� ���� ����. �� �ظ� ã�� ���̴�.
				printtable(board_size, aQueenBitRes, g_numsolutions + 1);
				++g_numsolutions;
				bitfield = *--pnStack;
				--numrows;
				continue;
			}
		}
	}

	//�ݻ�� �̹����� ����ϱ� ���ؼ� ���� ������ 2�� ���Ѵ�.
	g_numsolutions *= 2;
}

//������ ���� �� ����� ����Ѵ�.
void printResults(time_t* pt1, time_t* pt2)
{
	double secs;
	int hours, mins, intsecs;
	printf("End: \t%s", ctime(pt2));
	secs = difftime(*pt2, *pt1);
	intsecs = (int)secs;
	printf("Calculations took %d second%s.\n", intsecs, (intsecs == 1 ? " " : "s"));

	//��, ��, �ʸ� ����Ѵ�.
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

//N���� ���� ���α׷��� ���� ��ƾ
//��� �μ��� ���� ����� �־��ָ� ��.(ex: 4)
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

	//ü������ ũ�Ⱑ ��Ȯ�� ���� ���� �����ϴ��� ���θ� Ȯ���Ѵ�.
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