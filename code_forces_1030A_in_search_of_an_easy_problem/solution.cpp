#include <cstdio>
#include <cstdlib>

int main(int const argc, char * argv[])
{
    char const * const EASY = "EASY";
    char const * const HARD = "HARD";
    int N;
    int val;
    std::scanf("%d", &N);
    if(N < 1 || N > 100)  // per problem statement
    {
	std::exit(EXIT_FAILURE);
    }
    for(int i{ 0 }; i < N; ++i)
    {
	std::scanf("%d", &val);
	if(!val)
	{
	    continue;
	}
	else if(val == 1)
	{
	    std::puts(HARD);
	    std::exit(EXIT_SUCCESS);
	}
	else
	{
	    std::puts("non { 0, 1 } value read");
	    std::exit(EXIT_FAILURE);
	}
    }
    std::puts(EASY);
    std::exit(EXIT_SUCCESS);
}

