#include <cstdio>
#include <cstdlib>

inline int tanya_subtract(int N)
{
    if(N & 0x1 || N % 10)
    {
	return --N;
    }
    else
    {
        return N / 10;
    }
}

int main(int const argc, char * argv[])
{
    int N{ -1 };
    int K{ -1 };	// subtract K-times from N
    std::scanf("%d%d", &N, &K);	// inputs from stdin
    if(N < 0 || K < 0)
    {
	std::exit(EXIT_FAILURE);
    }
    for(int i{ 0 }; i < K; ++i)
    {
	N = tanya_subtract(N);
    }
    std::printf("%d\n", N);    // output on stdout
}
