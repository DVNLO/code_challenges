class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        vector<int> lucky_numbers;
        size_t const SIZE_COLS{ matrix[0].size() };
        size_t const SIZE_ROWS{ matrix.size() };
        vector<int> col_maxes(SIZE_COLS);
        vector<int> row_mins(SIZE_ROWS);
        for(size_t i{ 0 }; i < SIZE_ROWS; ++i)
        {
            row_mins[i] = matrix[i][0];
        }
        for(size_t j{ 0 }; j < SIZE_COLS; ++j)
        {
            col_maxes[j] = matrix[0][j];
        }
        for(size_t i{ 0 }; i < SIZE_ROWS; ++i)
        {
            for(size_t j{ 0 }; j < SIZE_COLS; ++j)
            {
                col_maxes[j] = max(col_maxes[j], matrix[i][j]);
                row_mins[i] = min(row_mins[i], matrix[i][j]);
            }
        }
        for(size_t i{ 0 }; i < SIZE_ROWS; ++i)
        {
            for(size_t j{ 0 }; j < SIZE_COLS; ++j)
            {
                if(matrix[i][j] == row_mins[i]
                    && matrix[i][j] == col_maxes[j])
                {
                    lucky_numbers.push_back(matrix[i][j]);
                }
            }
        }
        return lucky_numbers;
    }
};
