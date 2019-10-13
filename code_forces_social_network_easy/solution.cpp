#include <cstdio>
#include <cstdlib>
#include <deque>
#include <unordered_set>

void print(std::deque<unsigned> message_page, int N, int K)
{
    std::size_t const M = message_page.size();
    std::printf("%lu\n", M);
    for(int i = 0; i < M; ++i)
    {
        std::printf("%lu ", message_page[i]);
    }
    std::puts("");
}

int main(int const argc, char * argv[])
{
    int N = -1; // message count
    int K = -1; // message visibility limit
    std::scanf("%d%d", &N, &K);
    if(N < 1 || K > 200)
    {
        std::exit(EXIT_FAILURE);
    }
    std::unordered_set<unsigned> visible;
    std::deque<unsigned> message_page;
    unsigned val;
    int rc;
    for(int i = 0; i < N; ++i)
    {
        rc = std::scanf("%u", &val);
        if(rc != 1)
        {
            std::exit(EXIT_FAILURE);
        }
        if(visible.count(val))
        {
            continue;
        }
        else if(i < K) // not visible and not full
        {
            message_page.push_front(val);
            visible.insert(val);
        }
        else // not visible and full
        {
            visible.erase(message_page.back());
            message_page.pop_back();
            message_page.push_front(val);
            visible.insert(val);
        }
        print(message_page, N, K);
    }
    return 0;
}
       
