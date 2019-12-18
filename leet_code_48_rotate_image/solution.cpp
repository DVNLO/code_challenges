// The following rotates a 2D nxn matrix by 
// 90 degrees cloclwise.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        vector<int>::size_type const SIZE{ matrix.size() };
        if(SIZE < 2)
            return;
        vector<int>::size_type const LAYER_COUNT{ SIZE / 2 };
        for(vector<int>::size_type i{ 0 };
            i < LAYER_COUNT;
            ++i)
        {
            vector<int>::size_type const CYCLE_COUNT{ SIZE - i - 1 };
            for(vector<int>::size_type j{ i };
                j < CYCLE_COUNT;
                ++j)
            {
                // Counter clockwise swap cycle.
                swap(matrix[i][j], matrix[j][SIZE - i - 1]);    // right col with top row
                swap(matrix[i][j], matrix[SIZE - j - 1][i]);    // top row with left col
                swap(matrix[SIZE - j - 1][i], 
                        matrix[SIZE - i - 1][SIZE - j - 1]);    // left col with bottom row
            }            
        }
    }
};
