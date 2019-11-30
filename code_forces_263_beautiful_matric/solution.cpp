#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r;
	int c;
	int val;
	for(int i{ 0 }; i < 5; ++i)
	{
		for(int j{ 0 }; j < 5; ++j)
		{
			cin >> val;
			if(val)
			{
				r = i;
				c = j;
			}
		}
	}
	printf("%d\n", abs(r - 2) + abs(c - 2));
	return 0;
}
