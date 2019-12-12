// The following is a solution to hacker rank's original prompt
// staircase https://www.hackerrank.com/challenges/staircase/problem
// This was a great opportunity to review 2D-Matrix address conversion
// to linear addresses. I leveraged this to generate the entire stairs
// output in place with minimal operations. 
// This is a great example of optimization by beginning with the end
// in mind. Great problem. 

#include <bits/stdc++.h>

using namespace std;

inline int linear_idx(int const current_row,
                        int const current_column,
                        int const column_count)
{
    return (current_row * column_count) + current_column;
}

void staircase(int n)
{
    int const COLUMN_COUNT{ n + 1 };
    string stairs_out(n * COLUMN_COUNT, ' ');
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
    puts(stairs_out.c_str());
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}

