#include <stdio.h>
#include <string>
#include <iostream> 
using namespace std;

void print(string& buffer)
{
	int size = (int)buffer.size();
	if ((size >= 2 && size <= 50) == false)
	{
		cout << "ERROR!\n";
		return;
	}

	int count = 0;
	for (int j = 0; j < size; j++)
	{
		if (buffer[j] == '(')
		{
			count++;
		}
		else if (buffer[j] == ')')
		{
			count--;
		}
		if (count < 0)
		{
			cout << "NO\n";
			return;
		}
	}
	if (count == 0)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}

int main()
{
	int T = 0;
	cin >> T;

	if (T <= 0)
	{
		cout << "data input error!\n";
		return 0;
	}

	string buffer;
	for (int i = 0; i < T; i++)
	{
		cin >> buffer;
		print(buffer);
	}
	return 0;
}