#include <string>
#include <cstdio>
#include <iostream>
#include <chrono>

inline int linear_idx(int const current_row,
                        int const current_column,
                        int const column_count)
{
    return (current_row * column_count) + current_column;
}

// Complete the staircase function below.
void staircase(int n) 
{
    auto start = std::chrono::high_resolution_clock::now();
    int const COLUMN_COUNT{ n + 1 };
    std::string stairs_out(n * COLUMN_COUNT, ' ');
    for(int i{ 0 }; 
        i < n; 
        ++i)
    {
        int const FIRST_STAIR_IDX{ n - i - 1};
        int j{ FIRST_STAIR_IDX };
        for(;
            j < n;
            ++j)
        {
            stairs_out[linear_idx(i, j, COLUMN_COUNT)] = '#';
        }
        stairs_out[linear_idx(i, j, COLUMN_COUNT)] = '\n';
    }
    auto stop = std::chrono::high_resolution_clock::now(); 
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start); 
    std::puts(stairs_out.c_str());
    std::cout << duration.count() << std::endl;
}

int main()
{
    int v;
    std::cin >> v;
    staircase(v);
}
