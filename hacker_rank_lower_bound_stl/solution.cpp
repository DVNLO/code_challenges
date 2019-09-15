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

int main() {
    int const SIZE{ read_value() };
    std::vector<int> values{ read_values(SIZE) };
    int const QUERY_COUNT{ read_value() };
    int query_value;
    int query_value_idx;
    auto itr{ values.end() };
    for(int i{ 0 }; i < QUERY_COUNT; ++i)
    {
        query_value = read_value();
        itr = std::lower_bound(values.begin(), values.end(), query_value);
        query_value_idx = static_cast<int>(itr - values.begin() + 1);
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
