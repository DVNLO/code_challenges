// I optimized this solution by minimizing the total number of
// statements after recognizing that the row_vals vector could 
// be moved outside the inner for loop to prevent the destructor
// call and instead simply resize for each row. Additionally, 
// when resizing initialize the values to 1, so we do not need 
// to add them on the faces of the triangle. 
// I additionally used emplace back to construct the object in-place.

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> pascals_triangle;
        if(numRows < 1)
            return pascals_triangle;
        pascals_triangle.emplace_back(vector<int>{ 1 });
        vector<int> row_vals;
        for(int r{ 1 }; r < numRows; ++r)
        {
            row_vals.resize(r + 1, 1);
            for(int i{ 1 }; i < r; ++i)
            {
                row_vals[i] = pascals_triangle[r - 1][i - 1] 
                                + pascals_triangle[r - 1][i];
            }
            pascals_triangle.emplace_back(row_vals);
        }
        return pascals_triangle;
    }
};
