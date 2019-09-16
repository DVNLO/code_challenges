#include <cstdlib>
#include <cstdio>
#include <set>

int read_int_val()
{
    int val{ -1 };
    int read_count{ std::scanf("%d", &val) };
    if(read_count != 1)
    {
        std::exit(EXIT_FAILURE);
    }
    return val;
}

enum class QUERY_TYPE{ INSERT = 1, DELETE = 2, FIND = 3 };

std::pair<QUERY_TYPE, int> read_query()
{
    return { static_cast<QUERY_TYPE>(read_int_val()), read_int_val() };
}

void do_query_on(std::pair<QUERY_TYPE, int> const & query, 
                 std::set<int> & target)
{
    switch(query.first)
    {
        case QUERY_TYPE::INSERT:
            target.insert(query.second);
            break;
        case QUERY_TYPE::DELETE:
            target.erase(query.second);
            break;
        case QUERY_TYPE::FIND:
            auto itr{ target.end() };
            itr = target.find(query.second);
            if(itr == target.end())
            {
                std::puts("No");
            }
            else
            {
                std::puts("Yes");
            }
            break;
    }
}

int main() {
    int const QUERY_COUNT{ read_int_val() };
    std::set<int> vals;
    std::pair<QUERY_TYPE, int> query;
    for(int i{ 0 }; i < QUERY_COUNT; ++i)
    {
        query = read_query() ;
        do_query_on(query, vals);
    }
    return 0;
}
