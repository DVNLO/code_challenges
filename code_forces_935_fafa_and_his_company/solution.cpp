#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int TERMINAL = n / 2;
	int group_count = 0;
	for(int i = 1; i <= TERMINAL; ++i)
	{
		if(!(n % i))
		{
			++group_count;
		}
	}
	printf("%d", group_count);
}
