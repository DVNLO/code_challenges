/*
The following is a solution to prompt 695. Max Area of Island from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/max-area-of-island/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

class Solution {
public:
	int computeIslandArea(std::vector<std::vector<int>>& grid, const int& row, const int& column) {
		if (!grid[row][column])
			return 0;
		std::stack<std::pair<int, int>> coords;
		coords.push(std::pair<int, int>(row, column));
		while (!coords.empty()) {
			std::pair<int, int> top = coords.top();
			coords.pop();
			std::cout << grid[top.first][top.second];
		}

	}

	int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
		int maxArea = 0;
		int rows = grid.size();
		int columns = grid[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (grid[i][j]) { // == 1
					maxArea = std::max(maxArea, computeIslandArea(grid, i, j));
				}
			}
		}
		return maxArea;
	}
};


int main()
{
    return 0;
}

