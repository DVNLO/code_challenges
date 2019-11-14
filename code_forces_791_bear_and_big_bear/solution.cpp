#include <cstdio>

int main(int const argc, char * argv[])
{
    int a, b;
    std::scanf("%d %d", &a, &b);
    int t = 0;
    while(a <= b)
    {
        a *= 3;
	b *= 2;
	++t;
    }
    std::printf("%d", t);
}
