#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int bill_count = 0;
	while(n)
	{
		if(n >= 100)
		{
			n -= 100;
		}
		else if(n >= 20)
		{
			n -= 20;
		}
		else if(n >= 10)
		{
			n -= 10;
		}
		else if(n >= 5)
		{
			n -= 5;
		}
		else
		{
			n -= 1;
		}
		++bill_count;
	}
	printf("%d\n", bill_count);
}
