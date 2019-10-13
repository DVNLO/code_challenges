#include <cmath>
#include <cstdio>
#include <cstdlib>

void process_query()
{
    int good_count = -1;
    std::scanf("%d", &good_count);
    if(good_count < 0)
    {
        std::puts("invalid good count");
        std::exit(EXIT_FAILURE);
    }
    int val;
    double sum = 0;
    for(int i = 0; i < good_count; ++i)
    {
        std::scanf("%d", &val);
        sum += val;
    }
    int mean = static_cast<int>(std::ceil(sum / good_count));
    std::printf("%d\n", mean);        
}

int main(int const argc, char * argv[])
{
    int query_count = -1;
    std::scanf("%d", &query_count);
    if(query_count < 0)
    {
        std::puts("invalid query count");
        std::exit(EXIT_FAILURE);
    }
    for(int i = 0; i < query_count; ++i)
    {
        process_query();
    }
    return 0;
}
