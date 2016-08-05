#include <cstdio>
#include <cstring>
#include <stack>

#pragma warning(disable:4996)
using namespace std;

stack<char> LeftStack;
stack<char> RightStack;

int main()
{
	char c[600000];
	scanf("%s", &c);
	
	int num = strlen(c);
	for (int i = 0; i < num; i++)
	{
		LeftStack.push(c[i]);
	}
	
	int commandCount;
	scanf("%d", &commandCount);

	while (commandCount--)
	{
		char command;
		scanf(" %c", &command);

		switch (command)
		{
		case 'L':
			if (false == LeftStack.empty())
			{
				RightStack.push(LeftStack.top());
				LeftStack.pop();
			}
			break;
		case 'D':
			if (false == RightStack.empty())
			{
				LeftStack.push(RightStack.top());
				RightStack.pop();
			}
			break;
		case 'B':
			if (false == LeftStack.empty())
			{
				LeftStack.pop();
			}
			break;
		case 'P':
			char str;
			scanf(" %c", &str);
			LeftStack.push(str);
			break;
		}
	}
	
	while (false == LeftStack.empty())
	{
		RightStack.push(LeftStack.top());
		LeftStack.pop();
	}

	while (false == RightStack.empty())
	{
		printf("%c", RightStack.top());
		RightStack.pop();
	}

	printf("\n");
	
	getchar();
	//return 0;

}