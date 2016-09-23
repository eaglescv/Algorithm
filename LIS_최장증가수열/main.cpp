//출처:[ http://songsun0331.tistory.com/entry/CC-LIS-%EC%B5%9C%EC%9E%A5-%EC%A6%9D%EA%B0%80-%EC%88%98%EC%97%B4-%EB%AC%B8%EC%A0%9C ]
//---------------------------------------------------------------------------------
//LIS란 어떤 수열이 주어져 있을 때 오름차순으로 이루어져있는 부분수열의 최대 길이를 말한다.
//예를들어
//1 3 2 4 9 7 3
//라는 수열이 있다면 "증가수열"이 될 수 있는 경우들은
//1, 2, 4, 9
//3, 4, 9
//3, 4, 7
//1, 2, 3

//등등 모두 오름차순으로 증가하는 수들만 뽑아낸 것들 모두 해당된다.
//이 중에서 가장 길이가 긴 최장증가수열의 길이는 4 이다.이 길이를 구하는 문제를 해결하기위한 소스코드는 다음과 같다.
//입력과 출력은 파일 입출력으로 진행되었다.
//예시 입력파일은

//7
//1 3 2 4 9 7 3

//이었고, 결과물 출력파일의 답은
//4
//이다.
//---------------------------------------------------------------------------------
#include <iostream>

using namespace std;
//---------------------------------------------------------------------------------
//LIS 최장 증가 수열
//BOJ - https://www.acmicpc.net/problem/11053
//---------------------------------------------------------------------------------
int main()
{
	int n, MAX = 0, i, j;
	int data[10000] = { 0, };
	int D[10000] = { 0, };

	//ifstream in;
	//ofstream out;

	//in.open("input.txt");
	//out.open("output.txt");

	cin >> n;
	for (i = 1; i <= n; ++i)
		cin >> data[i];

	for (i = 1; i <= n; ++i)
	{
		D[i] = 1;
		for (j = 1; j <= i; ++j)
		{
			if ((data[i] > data[j]) && (D[i] < D[j] + 1))
			{
				D[i] = D[j] + 1;
			}
		}
	}

	for (i = 1; i <= n; ++i)
	{
		if (MAX < D[i])
			MAX = D[i];
	}

	cout << MAX;

	//in.close();
	//out.close();

	return 0;
}