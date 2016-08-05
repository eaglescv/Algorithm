#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <queue>

#pragma warning(disable:4996)
using namespace std;
queue<string> CommandQueue;
stack<char> LeftStack;
stack<char> RightStack;

int main()
{
	string str = "abcd";
	//cin >> str;

	for (int i = 0; i < (int)str.size(); i++)
	{
		LeftStack.push(str[i]);
	}

	int commandCount = 0;
	scanf("%d\n", &commandCount);

	char command[10];

	for (int i = 0; i < commandCount; i++)
	{
		gets(command);
		if (strlen(command) <= 0)
			continue;

		CommandQueue.push(command);
	}

	while (false == CommandQueue.empty())
	{
		string& command = CommandQueue.front();
		char val;
		switch (command[0])
		{
		case 'L':
			val = LeftStack.top();
			RightStack.push(val);
			LeftStack.pop();
			break;
		case 'D':
			val = RightStack.top();
			LeftStack.push(val);
			RightStack.pop();
			break;
		case 'B':
			LeftStack.pop();
			break;
		case 'P':
			if (command[2])
			{
				LeftStack.push(command[2]);
			}
			break;
		default:
			break;
		}
		CommandQueue.pop();
	}
	
	int i = 0;
	//return 0;
	getchar();
}