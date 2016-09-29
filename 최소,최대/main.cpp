#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int e;
	vector<int> list;
	for (int i = 0; i < n; i++)
	{
		cin >> e;
		list.push_back(e);
	}

	int min = list[0];
	int max = list[0];
	for (int i = 1; i < (int)list.size(); i++)
	{
		int cur = list[i];
		if (min > cur)
		{
			min = cur;
		}

		if (max < cur)
		{
			max = cur;
		}
	}
	printf("%d %d", min, max);
	return 0;
}