#include <cstdio>
#include <cstdlib>
#include <vector>

int read_value()
{
    int value{ -1 };
    int return_count{ std::scanf("%d", &value) };
    if(return_count != 1)
    {
        std::exit(EXIT_FAILURE);
    }
    return value;
}

std::vector<int> build_vector(int const SIZE)
{
    std::vector<int> vals(SIZE);
    for(int i{ 0 }; i < SIZE; ++i)
    {
        vals[i] = read_value();
    }
    return vals;
}

int main() 
{
    int const SIZE{ read_value() };
    std::vector<int> vals{ build_vector(SIZE) };
    int const erase_idx{ read_value() - 1 };    // read values are 1-indexed.
    vals.erase(vals.begin() + erase_idx);
    int const erase_idx_first{ read_value() - 1 };
    int const erase_idx_second{ read_value() - 1 };
    vals.erase(vals.begin() + erase_idx_first, 
               vals.begin() + erase_idx_second);
    std::printf("%lu\n", vals.size());
    for(auto itr{ vals.begin() }; itr != vals.end(); ++itr)
    {
        std::printf("%d ", *itr);
    }
    return 0;
}

