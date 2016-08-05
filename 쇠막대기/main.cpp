//#include <stdio.h>
//#include <string>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//struct Line
//{
//	int start;
//	int end;
//};
//
//vector<Line> LineVec;
//
//bool IsLajor(string& buffer, int currentIndex)
//{
//	if ((int)buffer.size() <= 0)
//	{
//		return false;
//	}
//
//	if (buffer[currentIndex] == ')')
//	{
//		if (buffer[currentIndex - 1] == '(')
//		{
//			return true;
//		}
//	}
//	return false;
//}
//
//int GetLajorCount(string& buffer, int startIndex, int endIndex)
//{
//	int count = 0;
//	for (int i = startIndex + 1; i < endIndex; i++)
//	{
//		if (IsLajor(buffer, i))
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//void MakeLine(string& buffer, int startIndex)
//{
//	int count = 0;
//	int i;
//	for (i = startIndex; i < (int)buffer.size(); i++)
//	{
//		if (buffer[i] == '(')
//		{
//			count++;
//		}
//		else if (buffer[i] == ')')
//		{
//			count--;
//		}
//
//		if (count == 0)
//		{
//			break;
//		}
//	}
//
//	if (i - startIndex > 1)
//	{
//		Line line;
//		line.start = startIndex;
//		line.end = i;
//		LineVec.push_back(line);
//	}
//}
//
//void TotalMakeLine(string& buffer)
//{
//	for (int i = 0; i < (int)buffer.size(); i++)
//	{
//		if (buffer[i] == '(')
//		{
//			MakeLine(buffer, i);
//		}
//	}
//}
//
//void Print(string& buffer)
//{
//	//막대기 수를 구한다.
//	//for( int i = 0; i < 막대기 수; i++)
//	//{
//	//  total += (막대기 안에 레이져 갯수를 구하고 1을 더한다.)
//	//}
//
//	int totalLineNum = 0;
//	TotalMakeLine(buffer);
//	for (int i = 0; i < (int)LineVec.size(); i++)
//	{
//		Line& line = LineVec[i];
//		totalLineNum += GetLajorCount(buffer, line.start, line.end);
//		totalLineNum += 1;
//	}
//	cout << totalLineNum << endl;
//}
//
//int main()
//{
//	string str = "()(((()())(())()))(())";
//	//string str = "(((()(()()))(())()))(()())";
//	//string str;
//	//cin >> str;
//
//	Print(str);
//	//return 0;
//	getchar();
//}

#include <iostream> 
#include <string> 
#include <stack> 
using namespace std;

int main() 
{
	string a = "()(((()())(())()))(())";
	//cin >> a;

	int n = a.size();
	stack<int> s;
	int ans = 0;
	int top = 0;

	for (int i = 0; i < n; i++) 
	{
		if (a[i] == '(') 
		{
			s.push(i);
		}
		else 
		{
			top = s.top();
			if (top + 1 == i)
			{
				s.pop();
				ans += s.size();
			}
			else 
			{
				s.pop();
				ans += 1;
			}
		}
	}

	cout << ans << endl;
	//return 0;
	getchar();
}
