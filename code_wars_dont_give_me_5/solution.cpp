#include <cstdio>
int main()
{
	int a{ -20 };
	for(int i{ 0 }; i > a; --i)
		printf("%d %d\n ", i,  i % 10);
}
