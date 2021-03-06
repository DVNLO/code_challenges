/*
The following is a solution to prompt 892. Surface Area of 3D Shapes
from leetcode.com. I have included two solutions surfaceArea_0 and
surfaceArea_1. Function 0 is my original niaeve solution from 
intuition, and solution 1 is my implementation after investigation. 
A majority of solution 1 can be credited to a discussion thread
on the leetcode website: https://leetcode.com/problems/surface-area-of-3d-shapes/discuss/163414/C++Java1-line-Python-Minus-Hidden-Area
The original prompt can be found here: https://leetcode.com/problems/surface-area-of-3d-shapes/description/
Author: Dan Vyeniel (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>

class Solution {
public:
	//implementation with further investigation
	int surfaceArea_1(std::vector<std::vector<int>>& grid) {
		int size = grid.size();
		int terminal_index = size - 1;
		int face_count = 0;
		for (int r = 0; r < size; r++) { //row
			for (int c = 0; c < size; c++) { //column
				int val = grid[r][c];
				if (val) {
					face_count += 4 * val + 2; //top, bottom, and faces
					if (r) { //remove shared north faces 
						face_count -= 2 * std::min(grid[r - 1][c], val);
					}
					if (c) { //remove shared west faces 
						face_count -= 2 * std::min(grid[r][c - 1], val);
					}
				}
			}
		}
		return face_count;
	}

	//original implementation
	int surfaceArea_0(std::vector<std::vector<int>>& grid) {
		int size = grid.size();
		int terminal_index = size - 1;
		int face_count = 0;
		for (int i = 0; i < size; i++) {    //north edge
			face_count += grid[0][i];
		}
		for (int i = 0; i < size; i++) {    //east edge
			face_count += grid[i][terminal_index];
		}
		for (int i = 0; i < size; i++) {    //south edge
			face_count += grid[terminal_index][i];
		}
		for (int i = 0; i < size; i++) {    //west edge
			face_count += grid[i][0];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				int val = grid[i][j];
				if (j + 1 < size) {  //east
					face_count += abs(val - grid[i][j + 1]);
				}
				if (i + 1 < size) {  //south
					face_count += abs(val - grid[i + 1][j]);
				}
				if (val) {   // -> add top & bottom
					face_count += 2;
				}
			}
		}
		return face_count;
	}

};

int main()
{
	Solution prompt;
	std::vector<std::vector<int> > grid = { {1, 2} , {3, 4} };
	prompt.surfaceArea_0(grid);
	prompt.surfaceArea_1(grid);
	return 0;
}

