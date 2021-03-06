/*
The following is a solution to prompt 463. Island Perimeter from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/island-perimeter/description/
Authod: Dan Vyeniel (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

class Solution {
public:
	int islandPerimeter(std::vector<std::vector<int>>& grid) {
		if (grid.empty()) return -1;
		int perimeter = 0;
		int height = grid.size();
		int width = grid[0].size();
		for (int row = 0; row < height; row++) {
			int column = 0;
			while (!grid[row][column])
				column++;
			for (column; column < width; column++) { //sum the non-adjacent perimeter
				if (grid[row][column]) {
					if (row == 0 || grid[row - 1][column] == 0) { //check top
						perimeter++;
					}
					if (row == height - 1 || grid[row + 1][column] == 0) { //check bottom
						perimeter++;
					}
					if (column == width - 1 || grid[row][column + 1] == 0) { //check right
						perimeter++;
					}
					if (column == 0 || grid[row][column - 1] == 0) { //check left
						perimeter++;
					}
				}
				//cout << row << "," << column << "==" << perimeter << endl;
			}
		}
		return perimeter;
	}
};

int main()
{
	Solution prompt;
	std::vector< std::vector<int> > map = { {0, 1, 0, 0},
											{1, 1, 1, 0},
											{0, 1, 0, 0},
											{1, 1, 0, 0} };
	std::cout << prompt.islandPerimeter(map) << std::endl;
    return 0;
}

