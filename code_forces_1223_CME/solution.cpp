#include <cstdio>
#include <cstdlib>
using namespace std;

// The solution here is yet another example of weakness with modulo
// arithmetic. I need to review modulo theory, but from an app
// driven approach, think that whenever we are dividing the 
// variables of the division algorithm are important. When thinking
// about this problem I notices the easy solution of dividing
// quickly but did not think to mod the answer, and did not 
// notice the special case when match count was 2. 
// The algorithm I came up with but timed out on submission 
// is shown as an iterative solution below.

int min_matches_needed(int const match_count)
{
    return match_count == 2 ? match_count : match_count % 2;
}


int min_matches_needed_iter(int const match_count)
{
    int a = 1;
    int b = 0;
    int c = match_count - 1;
    while((a + b < c) || !b)
    {
        --c;
        ++b;
    }
    return abs(a + b - c);
}

int main()
{
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; ++i)
    {
        int match_count;
        scanf("%d", &match_count);
        puts("------------");
        printf("%d\n", 
                min_matches_needed(match_count));
    }
}
