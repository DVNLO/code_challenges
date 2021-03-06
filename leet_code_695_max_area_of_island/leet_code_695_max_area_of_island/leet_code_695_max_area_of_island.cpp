/*
The following is a solution to prompt 695. Max Area of Island from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/max-area-of-island/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
My solution utilizes depth first search to travese adjacent 1's within the
grid. We consider a position "seen" when the coord is added to coords, and 
set the 1 -> 0;s
*/
#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

class Solution {
public:
	bool hasNorth(const std::vector<std::vector<int>>& grid, const std::pair<int, int>& coord) {
		return coord.first && grid[coord.first - 1][coord.second];
	}

	bool hasEast(const std::vector<std::vector<int>>& grid, const std::pair<int, int>& coord) {
		return coord.second != grid[0].size() - 1 && grid[coord.first][coord.second + 1];
	}

	bool hasSouth(const std::vector<std::vector<int>>& grid, const std::pair<int, int>& coord) {
		return coord.first!= grid.size() - 1 && grid[coord.first + 1][coord.second];
	}

	bool hasWest(const std::vector<std::vector<int>>& grid, const std::pair<int, int>& coord) {
		return coord.second && grid[coord.first][coord.second - 1];
	}

	int computeIslandArea(std::vector<std::vector<int>>& grid, const std::pair<int, int>& initial_coord) {
		int area = 0;
		std::stack<std::pair<int, int>> coords;
		coords.push(initial_coord);
		grid[initial_coord.first][initial_coord.second] = 0;
		while (!coords.empty()) {
			std::pair<int, int> top = coords.top();
			coords.pop();
			area++;
			if (hasNorth(grid, top)) {
				std::pair<int, int> north(top.first - 1, top.second);
				coords.push(north);
				grid[top.first - 1][top.second] = 0;
			}
			if (hasEast(grid, top)) {
				std::pair<int, int> east(top.first, top.second + 1);
				coords.push(east);
				grid[top.first][top.second + 1] = 0;
			}
			if (hasSouth(grid, top)) {
				std::pair<int, int> south(top.first + 1, top.second);
				coords.push(south);
				grid[top.first + 1][top.second] = 0;
			}
			if (hasWest(grid, top))	{
				std::pair<int, int> west(top.first, top.second - 1);
				coords.push(west);
				grid[top.first][top.second - 1] = 0;
			}
		}
		return area;
	}

	int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
		int maxArea = 0;
		int rows = grid.size();
		int columns = grid[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				if (grid[i][j]) { // == 1
					std::pair<int, int> coord(i , j);
					maxArea = std::max(maxArea, computeIslandArea(grid, coord));
				}
			}
		}
		return maxArea;
	}
};


int main()
{
	Solution prompt;
	std::vector<std::vector<int>> grid = { { 0,0,1,0,0,0,0,1,0,0,0,0,0 },
										{ 0,0,0,0,0,0,0,1,1,1,0,0,0 },
										{ 0,1,1,0,1,0,0,0,0,0,0,0,0 },
										{ 0,1,0,0,1,1,0,0,1,0,1,0,0 },
										{ 0,1,0,0,1,1,0,0,1,1,1,0,0 },
										{ 0,0,0,0,0,0,0,0,0,0,1,0,0 },
										{ 0,0,0,0,0,0,0,1,1,1,0,0,0 },
										{ 0,0,0,0,0,0,0,1,1,0,0,0,0 } };
	std::cout << prompt.maxAreaOfIsland(grid);
    return 0;
}

