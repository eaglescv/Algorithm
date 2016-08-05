#include <stdio.h>
#include <string>
#include <stack>
#include <queue>

#pragma warning(disable:4996)
using namespace std;
queue<string> CommandQueue;

int main()
{
	char str[100000] = "abcd";
	//scanf("%s", &str);

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
		switch (command[0])
		{
		case 'L':
			printf("L\n");
			break;
		case 'D':
			printf("D\n");
			break;
		case 'B':
			printf("B\n");
			break;
		case 'P':
			printf("P\n");
			break;
		default:
			break;
		}
		CommandQueue.pop();
	}
	
	//return 0;
	getchar();
}