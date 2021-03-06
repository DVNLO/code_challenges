/*
The following is a solution to prompt 807 Max Increase to Keep City Skyline 
from leetcode.com. The prompt can be found here: 
https://leetcode.com/problems/max-increase-to-keep-city-skyline/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		const int size = grid.size();
		vector<int> row_max_projection(size, 0);
		vector<int> column_max_projection(size, 0);
		for (int i = 0; i < size; i++) {  //row
			for (int j = 0; j < size; j++) {  //column
				if (grid[i][j] > row_max_projection[i])
					row_max_projection[i] = grid[i][j];
				if (grid[i][j] > column_max_projection[j])
					column_max_projection[j] = grid[i][j];
			}
		}
		int sum = 0;
		for (int i = 0; i < size; i++) {  //row
			for (int j = 0; j < size; j++) {  //column
				if (grid[i][j] < row_max_projection[i] &&
					grid[i][j] < column_max_projection[j])
					sum += min(row_max_projection[i], column_max_projection[j]) - grid[i][j];
			}
		}
		return sum;
	}
};

int main()
{
	/*
	[ [3, 0, 8, 4], 
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]
	*/
	vector<vector<int>> grid = { {3,0,8,4}, {2,4,5,7}, {9,2,6,3}, {0,3,1,0} };
	Solution prompt;
	cout << prompt.maxIncreaseKeepingSkyline(grid);
}