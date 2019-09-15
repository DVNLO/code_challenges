#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int read_value()
{
    int value{ -1 };
    int return_code{ std::scanf("%d", &value) };
    if(return_code != 1)
    {
        std::exit(EXIT_FAILURE);
    }
    return value;
}

std::vector<int> read_values(int const size)
{
    std::vector<int> values(size);
    for(int i{ 0 }; i < size; ++i)
    {
        values[i] = read_value();
    }
    return values;
}

int * lower_bound(int const * first, int const * last, int const val)
// the stl implementation of this algo is genius. I have essentiall 
// copied it here, translating it from iterators, as an exercise.
// www.cplusplus.com/reference/algorithm/lower_bound/
{
    int const * current{ nullptr };
    std::ptrdiff_t count{ last - first };
    std::ptrdiff_t step;
    while(count > 0)
    {
        current = first;
        step = count / 2;
        current += step;
        if(*current < val)
        {
            first = ++current;
            count -= ++step;
        }
        else
        {
            count = step;
        }
    }
    return const_cast<int *>(first);
}

int main() {
    int const SIZE{ read_value() };
    std::vector<int> values{ read_values(SIZE) };
    int const QUERY_COUNT{ read_value() };
    int query_value;
    int query_value_idx;
    int * itr{ nullptr };
    for(int i{ 0 }; i < QUERY_COUNT; ++i)
    {
        query_value = read_value();
        itr = lower_bound(&values[0], &values[SIZE], query_value);
        query_value_idx = static_cast<int>(itr - &values[0] + 1);
        if(*itr == query_value)
        {
            std::printf("Yes %d\n", query_value_idx);
        }
        else
        {
            std::printf("No %d\n", query_value_idx);
        }        
    }
    return 0;
}
